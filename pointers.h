#ifndef POINTERS_H
#define POINTERS_H

#include <stddef.h> // size_t

void printChallenge();
int** createDynamicArray(int x, int y);
int deleteDynamicArray(int*** array, int x, int y);
void swap(void* a, void* b, size_t size);
void charComparison();
double function1(int x, char* y);
void callFunctionPointer();
void safeFree(void** pointer);
void pointerPrediction();

#endif // !POINTERS_H

