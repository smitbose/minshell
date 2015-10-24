#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
int isbuiltin(char *);
int main()
{
	char buff[1024];
	char *built_ins[] = {
		"cd",
		"pwd",
		"exit"
	};
	while(1)
	{
		printf(">");
		scanf("%s",buff);
		if(isbuiltin(buff))
		{
			if(strcmp(buff,built_ins[0]) == 0)
			{
				printf("%s\n",buff);
				char *path = (char *)malloc(1024*sizeof(char));
				scanf("%s",path);
				if(path[0] == '/')
				{
					chdir(path);
				}
				else
				{
					char *temp = (char *)malloc(1024*sizeof(char));
					temp = getcwd(temp,1024);
					strcat(temp,"/");
					strcat(temp,path);
					chdir(temp);
					free(temp);
				}
				free(path);
			}
			else if(strcmp(buff,built_ins[1]) == 0)
			{
				char *temp = (char *)malloc(1024*sizeof(char));
				temp = getcwd(temp,1024);
				printf("%s\n",temp);
				free(temp);
			}
			else if(strcmp(buff,built_ins[2]) == 0)
			{
				return 0;
			}
		}
	}
	return 0;
}
int isbuiltin(char *arg)
{
	return 1;
}