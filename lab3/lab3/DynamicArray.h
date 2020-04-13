#pragma once
#include "Domain.h"

typedef magicItem TElem;

typedef struct {
	TElem* elems;
	int size;
	int capacity;
}DynamicArray;

DynamicArray* createDynamicArray(int capacity);
void destroy(DynamicArray* array);
void add(DynamicArray* array, TElem element);