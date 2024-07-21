#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main(void)
{
	int c;

	while ( (c = getc(stdin)) != EOF) 
		if (putc(c, stdout) == EOF)
			printf("Error stdout : %s\n", strerror(errno));
	
	if (ferror(stdin))
		printf("Error stdin : %s\n", strerror(errno));

	exit(0);
}
