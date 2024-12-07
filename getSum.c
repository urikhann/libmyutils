#include "getSum.h"

int getSum(int* array, int length) {
	int sum = 0;
	for (int i = 0; i < length; i++) {
		sum += array[i];
	}
	return sum;
}
