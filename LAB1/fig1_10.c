#include "apue.h"
#include <sys/wait.h>
#include <unistd.h>

static void	sig_int(int);		/* our signal-catching function */
int
main(void)
{
		char	buf[MAXLINE];	/* from apue.h */
		pid_t	pid;
		int		status;

		if (signal(SIGINT, sig_int) == SIG_ERR)
				err_sys("signal error");

		printf("%% ");	/* print prompt (printf requires %% to print %) */
		while (fgets(buf, MAXLINE, stdin) != NULL) {
				if (buf[strlen(buf) - 1] == '\n')
						buf[strlen(buf) - 1] = 0; /* replace newline with null */


				/************************/
				char *ptr;
				char *token,*command;
				ptr = buf;
				char bufcpy[1024],bufcpy2[1024];
				strcpy(bufcpy, buf);
				char* argument_list[10];
				for (int i=0; i<10; i++)
					argument_list[i] = NULL;
				const char s[2] = " ";
				command = strtok(bufcpy, s);
				if(strcmp(command ,"cd") == 0){
					command = strtok(NULL, s);
			      		chdir (command);
					printf("%% ");
					continue;
				}
				argument_list[0] = command;
				strcpy(bufcpy2, buf);
				token = strtok(bufcpy2,s);
				int i = 1;
				while(token != NULL) {
					token = strtok(NULL, s);
					if(token == NULL)
						break;
					argument_list[i] = malloc(sizeof(token));
					strcpy(argument_list[i], token);
					i++;
				}
			      /***********************/
					if ((pid = fork()) < 0) {
						err_sys("fork error");
					} else if (pid == 0) {		/* child */
						execvp(command, argument_list);
						err_ret("couldn't execute: %s", buf);
						exit(127);
					}
				/* parent */
				if ((pid = waitpid(pid, &status, 0)) < 0)
						err_sys("waitpid error");
				printf("%% ");
		}
		exit(0);
}

		void
sig_int(int signo)
{
		printf("interrupt\n%% ");
}

