#include <stdio.h>
#include <unistd.h>

int test()
{
	void *initial_brk = sbrk(0);
	printf("Initial end of data segment %p\n", initial_brk);

	// Allocate 1 of memory by increasing the end of the data segment
	size_t size = 0x5;	// 1MB
	void *new_brk = sbrk(size);
	if (new_brk == (void *)-1) {
			perror("sbrk");
			return 1;
	}
	new_brk = sbrk(0);
	printf("New end of data segment after allocation: %p\n", new_brk);

	// Allocate another 1 of memory by increasing the end of the data segment
	size = 0x5;	// 1MB
	new_brk = sbrk(size);
	if (new_brk == (void *)-1) {
			perror("sbrk");
			return 1;
	}
	
	new_brk = sbrk(0);
	printf("New end of data segment after allocation: %p\n", new_brk);

	size = 0xff;	// 1MB
	new_brk = sbrk(size);
	if (new_brk == (void *)-1) {
			perror("sbrk");
			return 1;
	}
	
	new_brk = sbrk(0);
	printf("WLC Test New end of data segment after allocation: %p\n", new_brk);

	// Deallocate the previously allocated memory by resetting the end of teh data segment
	if (sbrk(-size) == (void *)-1) {
		perror("sbrk");
		return 1;
	}

	new_brk = sbrk(0);
	printf("End of data segment after deallocation: %p\n", sbrk(0));

	return 0;
}

int main()
{
	test();

	return 0;
}
	
