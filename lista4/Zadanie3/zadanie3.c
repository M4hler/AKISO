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

int cd(char **);
int shell_exit();

int builtin_func_number();
int count_args(char **);
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

	if(strcmp(args[args_num - 1], "&") == 0)
	{	
		wait_child = false;
		args[args_num - 1] = NULL;
	}

	pid = fork();
	if(pid == 0)
	{
		if(execvp(args[0], args) == -1)
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





