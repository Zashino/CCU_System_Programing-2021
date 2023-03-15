#include "apue.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define	BUFFSIZE	8192

int main(void)
{
		int	n, fd;
		char	buf[BUFFSIZE];

		fd = open("/dev/null",O_RDWR|O_CREAT);

		while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
				if (write(fd, buf, n) != n)
						err_sys("write error");

		if (n < 0)
				err_sys("read error");

		exit(0);
}

