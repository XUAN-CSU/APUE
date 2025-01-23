#include <unistd.h>
#include <stdio.h>

#define FILEPATH "./test.txt"

int method_01()
{
    FILE *file = fopen(FILEPATH, "r");
    if (file == NULL) {
        perror("Error opening file");
        return -1;
    }

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }

    fclose(file);
    return 0;
}

int method_02()
{
    FILE *file = fopen(FILEPATH, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    int ch;
    while ((ch = fgetc(file)) != EOF) {
            putchar(ch);
    }

    fclose(file);
    return 0;
}

int method_03()
{
    FILE *file = fopen(FILEPATH, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    char word[50];
    while (fscanf(file, "%49s", word) ==  1) {
            printf("%s\n", word);
    }

    fclose(file);
    return 0;
}

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int method_04()
{
    int fd = open(FILEPATH, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return -1;
    }

    printf("File open OK, the file descriptor is :%d\n", fd);

    char buffer[128];
    size_t bytes_read = read(fd, buffer, sizeof(buffer) -1);

    if (bytes_read == -1) {
        perror("Error reading file");
        close(fd);
        return -1;
    }

    if (close(fd) == -1) {
        perror("Error closing file");
        return -1;
    }

    buffer[bytes_read] = '\0';
    printf("%s\n", buffer);

    return 0;
}

int test_open_max()
{
    long open_max = sysconf(_SC_OPEN_MAX);
    if (open_max == -1) {
        perror("sysconf failed");
    } else {
        printf("Maximum open file descriptors: %ld\n", open_max);
    }

    return 0;
}

int main()
{
    // test_open_max();
    
    // method_01();
    // method_02();
    // method_03();

    method_04();

    return 0;
}
