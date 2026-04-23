#include <stdio.h>
#include "strings.h"

void reverseString(char* string) {
	if (string == NULL) return;
	int length = 0;
	while (*(string + length) != '\0') {
		length++;
	}
	for (int i = 0; i < length / 2; i++) {
		char temp = *(string + length - 1 - i);
		*(string + length - 1 - i) = *(string + i);
		*(string + i) = temp;
	}
}

//return the updated length, or -1 for failure
int removeDuplicateCharacters(char* string, int length) {
	if (string == NULL) return -1;
	for (int i = 0; i < length; i++) {
		char temp = *(string + i);
		for (int j = i+1; j < length; j++) {
			if (*(string + j) == temp) {
				for (int k = j + 1; k < length; k++) {
					*(string + k - 1) = *(string + k);
				}
				*(string + length - 1) = '\0';
				length--;
				j--;
			}
		}
	}
	return length;
}

int stringLength(char* string) {
	int length = 0;
	while (*(string + length) != '\0') {
		length++;
	}
	return length;
}

char* stringCopy(char* destination, char* source, int destinationLength) {
	if (source == NULL || destination == NULL) return NULL;
	int sourceLength = stringLength(source);
	if (sourceLength == 0) return NULL;
	if (destinationLength <= sourceLength) return NULL;
	for (int i = 0; i < sourceLength; i++) {
		*(destination + i) = *(source + i);
	}
	*(destination + sourceLength) = '\0';
	return destination;	
}