#include <stdio.h>
#include <unistd.h>
int main()
{
	int status;
	char buff[1000];
	scanf("%s",buff);
	execlp(buff,buff,(char *)NULL);
	return 0;
}