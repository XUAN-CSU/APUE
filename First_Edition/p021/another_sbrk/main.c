#include <stdio.h>
#include <unistd.h>         // using for sbrk

int test()
{
    void *initial_break = sbrk(0);
    printf("Initial break: %p\n", initial_break);

    size_t size_1 = 1024;
    void *new_break_1 = sbrk(size_1);
    if (new_break_1 == (void *)-1) {
        perror("sbrk");
        return -1 << 1;
    }
    printf("New break after allocation: %p\n", sbrk(0));

    size_t size_2 = 1024;
    void *new_break_2 = sbrk(size_2);
    if (new_break_2 == (void *)-1) {
        perror("sbrk");
        return -1 << 2;
    }

    printf("New break after allocation: %p\n", sbrk(size_1));

    char *mem = (char *)initial_break;
    for (size_t i = 0; i < size_1; ++i) {
        mem[i] = 'A';       // Initialize with 'A'
    }
    printf("Memory initialized with 'A'.\n");
 
    printf("Memory contents: \n");
    for (size_t i = 0; i < size_1; ++i) {
        putchar(mem[i]);
    }
    putchar('\n');

}

int main()
{
    int ret = test();
    switch (ret) {
        case -2: 
            printf("something error in new_break_1\n");
            return 1;
            break;
        case -4:
            printf("something error in new_break_2\n");
            return 1;
            break;
        default:
            return 1;
            break;
    }
            
    return 0;
}

