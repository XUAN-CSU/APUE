#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <stdio.h>

#define FILEPATH "./test.txt"
int test()
{
    int fd = creat(FILEPATH, 0644);
    if (fd == -1) {
        perror("Error create file failed!\n");
        return -1;
    }

    printf("File create success, the file descriptor is %d\n", fd);
    return 0;
}

int main()
{
    test();

    return 0;
}


