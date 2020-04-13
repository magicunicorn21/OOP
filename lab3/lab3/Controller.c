#include "Controller.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

RuneCaller createRuneCaller(magicStock* stock)
{
	RuneCaller runeCaller;
	runeCaller.magicStock = stock;
	return runeCaller;
}

bool runeAdd(RuneCaller* runeCaller, int catalogueNumber, char state[], char type[], int value)
{
	//int catalogueNumberInt = atoi(catalogueNumber);
	//int valueInt = atoi(value);
	magicItem newItem = createMagicItem(catalogueNumber, state, type, value);
	return addMagicItem(runeCaller->magicStock, newItem);
}

bool runeRemove(RuneCaller* runeCaller, int catalogueNumber)
{
	//int catalogueNumberInt = atoi(catalogueNumber);
	return removeMagicItem(runeCaller->magicStock, catalogueNumber);
}

bool runeUpdate(RuneCaller* runeCaller, int catalogueNumber, char newState[], char newType[], int newValue)
{
	//int catalogueNumberInt = atoi(catalogueNumber);
	//int newValueInt = atoi(newValue);
	magicItem newItem = createMagicItem(catalogueNumber, newState, newType, newValue);
	return updateMagicItem(runeCaller->magicStock, newItem);
}

magicStock runeFilter(RuneCaller* runeCaller, char type[])
{
	magicStock filteredItems = createMagicStock();
	for (int index = 0; index < getSize(runeCaller->magicStock); index++)
	{
		magicItem item = getMagicItem(runeCaller->magicStock, index);
		if (strcmp(getType(&item), type) == 0)
		{
			addMagicItem(&filteredItems, item);
		}
	}
	return filteredItems;
}

magicStock* runeList(RuneCaller* runeCaller)
{
	return runeCaller->magicStock;
}

magicStock runeFilterSmallerThanValue(RuneCaller* runeCaller, int maxPotencyValue)
{
	magicStock filteredItems = createMagicStock();
	for (int index = 0; index < getSize(runeCaller->magicStock); index++)
	{
		magicItem item = getMagicItem(runeCaller->magicStock, index);
		if (getValue(&item) < maxPotencyValue)
		{
			addMagicItem(&filteredItems, item);
		}
	}
	return filteredItems;
}
