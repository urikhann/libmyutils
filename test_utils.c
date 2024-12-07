#include <stdio.h>
#include "getSum.h"
#include "getAverage.h"

int main() {
	int arr[5] = {0, 0, 0, 0, 0};
	int length = 5;

	printf("Enter 5 integers to calculate the sum and average: \n");

	for (int i = 0; i < length; i++) {
		printf("\tNumber %d: ", i + 1);
		if (scanf("%d", &arr[i]) != 1) {
			printf("Invalid input. Please enter an integer.\n");
			while (getchar() != '\n');
			i--;
		}
	}

	int sum = getSum(arr, length);
	double average = getAverage(arr, length);

	printf("Sum: %d\n", sum);
	printf("Average: %.2f\n", average);

	return 0;
}
