#include "apue.h"

int main(void)
{

	int c,cnt=0;
	
	while( (c = getc(stdin)) != EOF ){
		if(putc(c,stdout) == EOF)
			err_sys("output error");
		cnt++;
	}
		
	if(ferror(stdin))
		err_sys("input error");

	printf("iteration = %d\n",cnt);
	exit(0);
}

