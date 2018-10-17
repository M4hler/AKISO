#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define BUFF_SIZE 64
#define DELIMITERS " \t\n\r\a"

char * read_line();
char ** divide_line(char *);
int launch(char **);
int execute(char **);
int fork_pipes(char **);
char ** command_before_pipe(char **);
int spawn_process(int in, int out, char ** args);
int check_redirection(char **);

int cd(char **);
int shell_exit();

int builtin_func_number();
int count_args(char **);
int count_pipes(char **);
int (*builtin_functions[])(char **) = {&cd, &shell_exit};

char * builtin_strings[] = {"cd", "exit"};

int main(int argc, char * chargv[])
{
	char * line;
	char ** arguments;
	int status;
	
	do
	{
		printf("lsh-shell:");
		line = read_line();
		arguments = divide_line(line);
		status = execute(arguments);
	
		free(line);
		free(arguments);	
	} while(status);
}

char * read_line()
{
	char * line = NULL;
	ssize_t bufsize = 0;
	getline(&line, &bufsize, stdin);

	if(feof(stdin))
	{
		printf("\n");		
		exit(EXIT_FAILURE);
	}

	return line;
}

char ** divide_line(char * line)
{
	int buffer_size = BUFF_SIZE;
	int position = 0;
	char ** split_arguments = malloc(sizeof(char*) * BUFF_SIZE);
	char * argument;

	if(split_arguments == NULL)
	{
		fprintf(stderr, "allocation error");
		exit(EXIT_FAILURE);
	}

	argument = strtok(line, DELIMITERS);
	while(argument != NULL)
	{
		split_arguments[position] = argument;
		position++;

		if(position >= buffer_size)
		{
			buffer_size += BUFF_SIZE;
			split_arguments = realloc(split_arguments, buffer_size * sizeof(char *));

			if(split_arguments == NULL)
			{
				fprintf(stderr, "reallocation error");
				exit(EXIT_FAILURE);
			}
		}
		argument = strtok(NULL, DELIMITERS);
	}
	split_arguments[position] = NULL;
	return split_arguments;
}

int launch(char ** args)
{
	pid_t pid, wpid;
	int status;

	int args_num = count_args(args);
	bool wait_child = true;

	int pipes_num = count_pipes(args);
	int redirection = check_redirection(args);

	if(strcmp(args[args_num - 1], "&") == 0)
	{	
		wait_child = false;
		args[args_num - 1] = NULL;
	}

	pid = fork();
	if(pid == 0)
	{
		if(pipes_num != 0)
		{
			fork_pipes(args);
		}		
		else if(execvp(args[0], args) == -1)
		{
			perror("child process");
		}
		exit(EXIT_FAILURE);
	}
	else if(pid < 0)
	{
		perror("error forking");
	}
	else
	{
		if(wait_child == true)
		{
			do
			{
				wpid = waitpid(pid, &status, WUNTRACED);
			} while(!WIFEXITED(status) && !WIFSIGNALED(status));
		}
	}

	return 1;
}

int cd(char ** args)
{
	if(args[1] == NULL)
	{
		fprintf(stderr, "expected argument in cd\n");
	}
	else
	{
		if(chdir(args[1]) != 0)
		{
			perror("cd error");
		}
	}
	return 1;
}

int shell_exit()
{
	return 0;
}

int execute(char ** args)
{
	if(args[0] == NULL)
	{
		return 1;
	}

	for(int i = 0; i < builtin_func_number(); i++)
	{
		if(strcmp(args[0], builtin_strings[i]) == 0)
		{
			return (*builtin_functions[i])(args);
		}
	}

	return launch(args);
}

int builtin_func_number()
{
	return (sizeof(builtin_strings) / sizeof(char *));
}

int count_args(char ** args)
{
	int i = 0;
	char * p = args[0];
	while((*p) != NULL)
	{
		i++;
		p += strlen(p);
		p++;
	}
	return i;
}

int count_pipes(char ** args)
{
	int number = 0;	
	for(int i = 0; i < count_args(args); i++)
	{	
		if(strcmp(args[i], "|") == 0)
		{	
			number++;
		}
	}
	return number;
}

int fork_pipes(char ** args)
{
	pid_t pid;
	int in = 0;
	int fd[2];

	int x = 0;
	for(int i = 0; i < count_pipes(args); i++)
	{
		char ** a = malloc(sizeof(char *) * BUFF_SIZE);
		int position = 0;

		for(int j = x; j < count_args(args); j++)
		{
			if(strcmp(args[j], "|") == 0)
			{			
				x++;				
				break;
			}
			if(strcmp(args[j], "\0") == 0)
				break;

			a[position] = args[j];
			position++;
			x++;
		}

		pipe(fd);

		spawn_process(in, fd[1], a);

		close(fd[1]);

		in = fd[0];
	}

	if(in != 0)
		dup2(in, 0);

	char ** a = malloc(sizeof(char *) * BUFF_SIZE);
	int position = 0;
	for(int j = x; j < count_args(args); j++)
	{
		if(strcmp(args[j], "|") == 0)
		{			
			x++;				
			break;
		}
		if(strcmp(args[j], "\0") == 0)
			break;

		a[position] = args[j];
		position++;
		x++;
	}
	
	return execvp(a[0], a);
}

int spawn_process(int in, int out, char ** args)
{
	pid_t pid;
	if((pid = fork()) == 0)
	{
		if(in != 0)
		{
			dup2(in, 0);
			close(in);
		}

		if(out != 1)
		{
			dup2(out, 1);
			close(out);
		}
		return execvp(args[0], args);
	}
	return pid;
}

int check_redirection(char ** args)
{
	for(int i = 0; i < count_args(args); i++)
	{
		if(strcmp(args[i], "<") == 0)
			return -1;
		if(strcmp(args[i], ">") == 0)
			return 1;
	}
	return 0;
}


