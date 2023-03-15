#include "apue.h"

int main(void)
{
	char buf[MAXLINE];
	int cnt=0;

	setvbuf(stdin,buf,_IOFBF,MAXLINE);
	setvbuf(stdout,buf,_IOFBF,MAXLINE);

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

