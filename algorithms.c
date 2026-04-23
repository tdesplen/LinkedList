#include <stdio.h>
#include "algorithms.h"

//Find the missing number of a sorted array with exactly one value from 1 to N except the missing number
int findMissingNumber(int* array, int length) {
	if (array == NULL || length <= 0) return -1;
	int n = length + 1;
	int expectedSum = n * (n + 1) / 2;
	int arraySum = 0;
	for (int i = 0; i < length; i++) {
		arraySum = arraySum + array[i];
	}
	return expectedSum - arraySum;
}

//return the index of the first occurrence of an integer in a sorted array
int binarySearch(int* array, int length, int targetValue) {
	if (array == NULL) return -1;
	int right = length - 1;
	int left = 0;
	int index = -1;
	while (left <= right) {
		int middle = (right + left) / 2;
		if (targetValue <= *(array + middle)) {
			if (*(array + middle) == targetValue) index = middle;
			right = middle - 1;
		}
		else {
			left = middle + 1;
		}
	}
	return index;
}