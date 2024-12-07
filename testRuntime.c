#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main() {
	void* handle;
	int (*getSum)(int*, int);
	double (*getAverage)(int*, int);
	char* error;

	handle = dlopen("./libmyutils.so", RTLD_LAZY);
	if (!handle) {
		fprintf(stderr, "%s\n", dlerror());
		exit(1);
	}

	getSum = dlsym(handle, "getSum");
	if ((error = dlerror()) != NULL) {
		fprintf(stderr, "%s\n", error);
		exit(1);
	}

	getAverage = dlsym(handle, "getAverage");
	if ((error = dlerror()) != NULL) {
		fprintf(stderr, "%s\n", error);
		exit(1);
	}

	int arr[5];
	int length = 5;

	printf("Enter 5 integers to calculate the sum and average:\n");

	for (int i = 0; i < length; i++) {
		printf("\tNumber %d: ", i + 1);
		scanf("%d", &arr[i]);
	}

	int sum = getSum(arr, length);
	double average = getAverage(arr, length);

	printf("Sum: %d\n", sum);
	printf("Average: %.2f\n", average);

	return 0;
}
