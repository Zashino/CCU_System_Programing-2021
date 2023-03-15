#include "apue.h"

int main(void)
{
	char buf[MAXLINE];
	int cnt=0;

	while( (fgets(buf,MAXLINE,stdin)) != NULL ){
		if(fputs(buf,stdout) == EOF)
			err_sys("output error");
		cnt++;
	}
		
	if(ferror(stdin))
		err_sys("input error");

	printf("iteration = %d\n",cnt);
	exit(0);
}

