#include "apue.h"
#include <setjmp.h>
#include <string.h>

#define FILENAME "emailTest.txt"

jmp_buf	jmpbuffer;
void	do_line(char *);//start to measure email
void	compare_at(char *);//@
void	compare_sharp(char *);//#
void	compare_asterisk (char *);//*
void	compare_doubleDot(char *);//..
void	compare_dot(char *);//___@___.___

int main(void)
{
		char	line[MAXLINE];
		FILE* fp;
		fp = fopen(FILENAME,"r");
		int i;
		if((i = setjmp(jmpbuffer)) != 0){
			if (i == 1)
					printf("Email format error: at least one @ \n");
			else if(i == 2)
					printf("Email format error: more than one @ \n");
			
			//write your code here
			else if(i == 3)
					printf("Email format error: can't exist # \n");
			else if(i == 4)
					printf("Email format error: can't exist * \n");
			else if(i == 5)
					printf("Email format error: can't exist ..\n");
			else if(i == 6)
					printf("Email format error: at least one . behind the @\n");
		}
		while (fgets(line, MAXLINE, fp) != NULL)
		{	
				printf("------------------------------------------------\n");
				printf("%s",line);
				do_line(line);		
		}
		exit(0);
}
void do_line(char *str)		/* process one line of input */
{
		compare_at(str);
		printf ("valid email address!\n");
		return;
}	
void compare_at(char *str)
{
		int counter = 0;
		char* 	cptr;
		char*	temp;	
		if((cptr = strchr(str,'@')) == NULL) 
				longjmp(jmpbuffer, 1);  //at least one @	
		temp = cptr;
		while((cptr = strchr(temp,'@')) != NULL)
		{							
				printf ("@ found at %ld\n",cptr-str+1);				
				counter++;
				temp = cptr+1;			
		}
		if(counter > 1)
				longjmp(jmpbuffer, 2);	//more than one @	
		compare_sharp(str);
		return;
}
void compare_sharp(char *str)
{
		//write your code here
		char*	cptr;
		char*	temp;
		if((cptr = strchr(str,'#')) == NULL)
			compare_asterisk(str);	//no #
		else{
			temp = cptr;
			while((cptr = strchr(temp,'#')) != NULL)
			{
				printf("# found at %ld(error occur)\n",cptr-str+1);
				temp = cptr+1;
			}
			longjmp(jmpbuffer, 3);	//more than one #
		}
		return;
}
void compare_asterisk(char *str)
{
		//write your code here
		char*   cptr;
                char*   temp;
                if((cptr = strchr(str,'*')) == NULL)
                        compare_doubleDot(str);  //no *
                else{
                        temp = cptr;
                        while((cptr = strchr(temp,'*')) != NULL)
                        {
                                printf("* found at %ld(error occur)\n",cptr-str+1);
                                temp = cptr+1;
                        }
                        longjmp(jmpbuffer, 4);  //more than one *
                }
		return;
}
void compare_doubleDot(char *str)
{	
		//write your code here
		char*   cptr;
                char*   temp;
                if((cptr = strstr(str,"..")) == NULL)
                        compare_dot(str);  //no ..
                else{
                        temp = cptr;
                        while((cptr = strstr(temp,"..")) != NULL)
                        {
                                printf(".. found at %ld(error occur)\n",cptr-str+1);
                                temp = cptr+1;
                        }
                        longjmp(jmpbuffer, 5);  //more than one ..
                }
		return;
}
void compare_dot(char *str)
{
		//write your code here
		char*	cptr;
		char*	temp;
		temp = strchr(str,'@');
		temp++;
		if((cptr = strchr(temp,'.')) == NULL)
				longjmp(jmpbuffer, 6);//no . behind @
		return;
}
