#include "Domain.h"
#include <stdio.h>

magicItem createMagicItem(int catalogueNumber, char state[], char type[], int value)
{
	magicItem magicItem;
	magicItem.catalogueNumber = catalogueNumber;
	strcpy(magicItem.state, state);
	strcpy(magicItem.type, type);
	magicItem.value = value;
	return magicItem;
}

int getCatalogueNumber(magicItem* item)
{
	return item->catalogueNumber;
}

char* getState(magicItem* item)
{
	return item->state;
}

char* getType(magicItem* item)
{
	return item->type;
}

int getValue(magicItem* item)
{
	return item->value;
}