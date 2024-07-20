#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
	struct dirent *de;
	DIR *dr;

	if (argc == 1) 
		dr = opendir(".");
	else
		dr = opendir(argv[1]);
	
	if (dr == NULL) {
		printf("Could not open directory\n");
		return 1;
	}

	while ((de = readdir(dr)) != NULL) {
		printf("%s\n", de->d_name);
	}

	closedir(dr);

	return 0;
}
