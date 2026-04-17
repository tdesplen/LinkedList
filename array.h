#ifndef ARRAY_H
#define ARRAY_H

typedef struct Array {
	int* container;
	int size;
	int capacity;
} Array;

Array* Array_create(int capacity);
int Array_increaseCapacity(Array** array, int newCapacity);
int Array_insert(Array** array, int data, int position);
int Array_remove(Array* array, int position);
int Array_clear(Array* array);
int Array_getValue(Array* array, int position, int* error);
int Array_setValue(Array* array, int data, int position);
int Array_destroy(Array** array);

#endif // !ARRAY_H

