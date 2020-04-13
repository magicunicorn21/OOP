#pragma once
#include "Repository.h"

typedef struct {
	magicStock* magicStock;
} RuneCaller;

RuneCaller createRuneCaller(magicStock* stock);
bool runeAdd(RuneCaller* runeCaller, int catalogueNumber, char state[], char type[], int value);
bool runeRemove(RuneCaller* runeCaller, int catalogueNumber);
bool runeUpdate(RuneCaller* runeCaller, int catalogueNumber, char newState[], char newType[], int newValue);
magicStock runeFilter(RuneCaller* runeCaller, char type[]);
magicStock* runeList(RuneCaller* runeCaller);
magicStock runeFilterSmallerThanValue(RuneCaller* runeCaller, int maxPotencyValue);