#define NULL 0
int main(int argc, char * argv[])
{
	char * name[2];
	name[0] = "bash";
	name[1] = NULL;
	execvp("/bin/bash", name);
	setuid(0);
	return 0;
}
