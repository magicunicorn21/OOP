#include "DynamicArray.h"
#include <stdio.h>
#include <stdlib.h>

DynamicArray* createDynamicArray(int capacity)
{
	DynamicArray* dynamicArray = (DynamicArray*)malloc(sizeof(DynamicArray));
	if (dynamicArray == NULL)
		return NULL;
	dynamicArray->capacity = capacity;
	dynamicArray->size = 0;
	dynamicArray->elems = (TElem*)malloc(capacity * sizeof(TElem));
	if (dynamicArray->elems == NULL)
		return NULL;
	return dynamicArray;
}

void destroy(DynamicArray* array)
{
	if (array == NULL)
		return;
	free(array->elems);
	array->elems = NULL;
	free(array);
}

void resize(DynamicArray* array)
{
	if (array == NULL)
		return;
	array->capacity *= 2;
	TElem* auxiliarElems = (TElem*)realloc(array->elems, array->capacity * sizeof(TElem));
	if (auxiliarElems == NULL)
		return; // array cannot be resized (TODO - return error code and check when resizing)
	array->elems = auxiliarElems;
}

void add(DynamicArray* array, TElem element)
{
	if (array == NULL)
		return;
	if (array->elems == NULL)
		return;
	if (array->size == array->capacity)
		printf("The capasity was reached!");
	else
	{
		array->elems[array->size] = element;
		array->size++;
	}
}