#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
	for (int i = (*array)->size; i > position; i--) {
		*((*array)->container + i) = *((*array)->container + i - 1);
	}
	*((*array)->container + position) = data;
	(*array)->size++;
	return 0;
}
 
//assuming we don't need to return the removed value, good to fix this eventually
int Array_remove(Array* array, int position) {
	if (array == NULL) return 1;
	if (position < 0 || position >= array->size) return 1;

	for (int i = position; i < array->size-1; i++) {
		*(array->container + i) = *(array->container + i + 1);
	}
	*(array->container + array->size - 1) = 0;
	array->size--;
	return 0;
}

int Array_clear(Array* array) {
	if (array == NULL) return 1;
	for (int i = 0; i < array->size; i++) {
		*(array->container + i) = 0; //not necessary, but prevents sensitive data from continuing to live in memory
	}
	array->size = 0;
	return 0;
}

//return 0, error = NULL AND return 0, error != NULL, *error != 0 are both valid error conditions
//should likely add an enum for errors or at least a definition in comments
int Array_getValue(Array* array, int position, int* error) {
	if (error == NULL) return 0;
	if (array == NULL) {
		*error = -1;
		return 0;
	}
	if (position < 0 || position >= array->size) {
		*error = -1;
		return 0;
	}
	*error = 0;
	return *(array->container + position);
}

//returns error code
int Array_setValue(Array* array, int data, int position) {
	if (array == NULL) return 1;
	if (position < 0 || position >= array->size) return 1;

	*(array->container + position) = data;
	return 0;
}

//return error code
int Array_destroy(Array** array) {
	if (array == NULL || *array == NULL ) return 1;
	for (int i = 0; i < (*array)->size; i++) {
		*((*array)->container + i) = 0; //not necessary, but prevents sensitive data from continuing to live in memory
	}
	free((*array)->container);
	free(*array);
	*array = NULL;
	return 0;
}