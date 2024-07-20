#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>			// for using the exit()

int main(void)
{
	FILE *file = fopen("nonexistentfile.txt", "r");
	if (!file) 
		printf("Error opening file : %s\n", strerror(errno));
	else {
		if (fclose(file) != 0)
			printf("Error opening file : %s\n", strerror(errno));
		else
			printf("File closed successfully.\n");
	}
	exit(0);
}
