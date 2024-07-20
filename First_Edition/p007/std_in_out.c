#include <unistd.h>
#include <stdlib.h>			// for using the exit()
#include <stdio.h>
#include <errno.h>			// for using the strerror

#define BUFFSIZE 8192

int main(void)
{
	int n;
	char buf[BUFFSIZE];

	while ( (n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
		if (write(STDOUT_FILENO, buf, n) != n)
			perror("Write error");

		if (n < 0)
		perror("Read rror");

		exit(0);
}
