#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFF_SIZE 64

int myprintf(const char *, ...);
void read_string(char *);
void read_decimal(char *, int);
char * num_to_string(int, int);
int num_length(int, int);

int main(int argc, char * argv[])
{
	myprintf("test %s dalej %s i koniec %d elo %b binarnie %x hexadecymalnie\n", "tekst w srodku", "PWR", 222, 10, 15);
	myprintf("\n");
}

int myprintf(const char * format, ...)
{
	char * arg_pointer = (char *)&format + sizeof(format);
	const char * p = format;

	while(*p != '\0')
	{
		if(*p == '%')
		{
			p++;
			if(*p == '\0')
			{
				break;
			}			
			else if(*p == 's')
			{ 
				read_string(arg_pointer);
				arg_pointer += sizeof(char *);
			}
			else if(*p == 'd')
			{
				read_decimal(arg_pointer, 10);
				arg_pointer += sizeof(int *);
			}
			else if(*p == 'b')
			{
				read_decimal(arg_pointer, 2);
				arg_pointer += sizeof(int *);
			}
			else if(*p == 'x')
			{
				read_decimal(arg_pointer, 16);
				arg_pointer += sizeof(int *);
			}
		}
		else
		{
			write(1, p, 1);
		}

		p++;
	}
}

void read_string(char * arg)
{	
	char * p = *((char **)arg);

	while(*p != '\0')
	{
		write(1, p, 1);
		p++;
	}
}

void read_decimal(char * arg, int base)
{
	int number = *((int *)arg);
	write(1, num_to_string(number, base), num_length(number, base));
}

char * num_to_string(int arg, int base)
{
	int length = num_length(arg, base);
	char * num_string = malloc(length * sizeof(char));

	if(base == 2 || base == 10)
	{
		for(int i = length - 1; i >= 0; i--)
		{
			num_string[i] = (char)('0' + (arg % base));
			arg /= base;
		}
	}
	else if(base == 16)
	{
		for(int i = length - 1; i >= 0; i--)
		{
			int tmp = arg % base;
			if(tmp >= 10)
			{
				num_string[i] = (char)(55 + tmp);
			}
			else
			{
				num_string[i] = (char)('0' + (arg % base));
			}
			arg /= base;
		}
	}
	return num_string;
}

int num_length(int arg, int base)
{
	int lenght = 1;
    	int i = 1;

    	while((arg / (base * i)) != 0)
    	{
       		lenght++;
       		i *= base;
    	}
    	return lenght;
}





