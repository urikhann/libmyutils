#include "getAverage.h"

double getAverage(int* array, int length) {
	if (length == 0) {
		return 0.0;
	}
	int sum = 0;
	for (int i = 0; i < length; i++) {
		sum += array[i];
	}
	return (double)sum / length;
}
