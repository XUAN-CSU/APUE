#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>			// using for the execlp()
#include <stdlib.h>			// using for the exit(0)
#include <errno.h>

#define MAXLINE 4096
static void sig_int(int);

void err_ret(const char *msg);

int main(void)
{
	char buf[MAXLINE];
	pid_t pid;
	int status;

	if (signal(SIGINT, sig_int) == SIG_ERR)
		perror("signal error");

	printf("%% ");
	while (fgets(buf, MAXLINE, stdin) != NULL) {
		buf[strlen(buf) - 1] = 0;

		if ( (pid = fork()) < 0)
			perror("fork error");

		else if (pid == 0) {
			execlp(buf, buf, (char *) 0);
			err_ret(buf);
			exit(127);
		}

		if ( (pid == waitpid(pid, &status, 0) ) < 0)
			perror("waitpid error");
		printf("%% ");
	}
	exit(0);
}
			
void sig_int(int signo)
{
	printf("interrupt\n%% ");
}

void err_ret(const char *msg)
{
 	fprintf(stderr, "WLC Error: %s: %s\n", msg, strerror(errno));
}
