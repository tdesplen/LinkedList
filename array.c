#include <stdio.h>
#include "array.h"

//create a new array
Array* Array_create(int capacity) {
	if (capacity < 0) return NULL;
	Array* array = malloc(sizeof(struct Array));
	if (array == NULL) return NULL;
	array->capacity = capacity;
	array->size = 0;
	//create the container
	array->container = malloc(sizeof(int) * capacity);
	if (array->container == NULL) {
		free(array);
		return NULL;
	}
	return array;
}

int Array_increaseCapacity(Array** array, int newCapacity) {
	if (array == NULL) return 1;
	if (newCapacity < 0 || newCapacity <= (*array)->capacity) return 1;
	Array* biggerArray = Array_create(newCapacity);
	if (biggerArray == NULL) return 1;
	memcpy(biggerArray->container, (*array)->container, sizeof(int) * (*array)->size);
	biggerArray->size = (*array)->size;
	Array_destroy(array);
	*array = biggerArray;
	return 0;
}

int Array_insert(Array** array, int data, int position) {
	//do input parameter checks
	if (array == NULL) return 1;
	if (position < 0 || position > (*array)->size) return 1;

	if ((*array)->size == (*array)->capacity) {
		int result = Array_increaseCapacity(array, (*array)->capacity * 2 + 1);
		if (result == 1) return 1;
	}
	//shift all the values from position to size-1 to the right. Here I start at the end and work backwards
	for (int i = (*array)->size - 1; i > position; i--) {
		*((*array)->container + i) = *((*array)->container + i - 1);
	}
	*((*array)->container + position) = data;
	(*array)->size++;
	return 0;
}

int Array_remove(Array* array, int position) {
	


}

void Array_clear(Array* array) {

}
int Array_getValue(Array* array, int position) {

}
void Array_setValue(Array* array, int data, int position) {

}
void Array_destroy(Array** array) {

}