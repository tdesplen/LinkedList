#ifndef ARRAY_H
#define ARRAY_H

#include <stdlib.h>
#include <string.h>

typedef struct Array {
	int* container;
	int size;
	int capacity;
} Array;

void Array_create(Array** array, int capacity);
void Array_increaseCapacity(Array* array, int newCapacity);
void Array_insert(Array* array, int data, int position);
int Array_remove(Array* array, int position);
void Array_clear(Array* array);
int Array_getValue(Array* array, int position);
void Array_setValue(Array* array, int data, int position);
void Array_destroy(Array** array);

#endif // !ARRAY_H

