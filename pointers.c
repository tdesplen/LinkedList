#include <stdio.h>
#include <stdlib.h>
#include "pointers.h"

void printChallenge() {
	int a[] = { 10,20,30 };
	int* p = a;
	printf("%d %d\n", *(p + 1), *p + 1);
	//prints: 20, 11
}

//x and y are the dimensions of the 2D array
int** createDynamicArray(int x, int y) {
	int** dynamicArray = malloc(sizeof(int*) * x);
	if (dynamicArray == NULL) return NULL;

	for (int i = 0; i < x; i++) {
		dynamicArray[i] = malloc(sizeof(int) * y);
		if (dynamicArray[i] == NULL) {
			for (int k = 0; k < i; k++) {
				free(dynamicArray[k]);
			}
			free(dynamicArray);
			return NULL;
		}
		for (int j = 0; j < y; j++) {
			dynamicArray[i][j] = i * 10 + j;
		}
	}
	return dynamicArray;
}

//going to zero out the data before freeing
int deleteDynamicArray(int*** array, int x, int y) {
	if (array == NULL || *array == NULL) return 1;
	if (x <= 0 || y <= 0) return 1;
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			(*array)[i][j] = 0;
		}
		free((*array)[i]);
	}
	free(*array);
	*array = NULL;
	return 0;
}

//generic swap: size in bytes
void swap(void* a, void* b, size_t size) {
	if (a == NULL || b == NULL) return;
	if (size == 0) return;
	char* tempA = (char*)a;
	char* tempB = (char*)b;
	for (int i = 0; i < size; i++) {
		char swapTemp = *(tempA+i);
		*(tempA + i) = *(tempB + i);
		*(tempB + i) = swapTemp;
	}
}

void charComparison() {
	char* s1 = "hello"; //pointer lives in the stack, but string literal lives in read-only memory, cannot modify the characters just the pointer
	//essentially the string literal for s1 is a 'const char*' but C doesn't define it as 'const' so it causes runtime faults, but compiles fine
	char s2[] = "hello"; //string literal lives on the stack, can modify the characters
}

double function1(int x, char* y) {
	return 0.0;
}

void callFunctionPointer() {
	int x = 10;
	char* y = "yup";
	double (*functionPointer)(int, char*) = function1;
	double result = functionPointer(x, y);
}

void safeFree(void** pointer) {
	if (pointer == NULL) return;
	if (*pointer == NULL) return;
	free(*pointer);
	*pointer = NULL;
}

void pointerPrediction() {
	int a = 10;
	int b = 20;
	int* p = &a;
	int** pp = &p;

	printf("%d\n", *p); //10
	printf("%d\n", **pp); //10

	*p = 30;
	printf("%d\n", a); //30

	p = &b;
	printf("%d\n", *p); //20
	printf("%d\n", **pp); //20

	*pp = &a;
	printf("%d\n", *p); //30
}


