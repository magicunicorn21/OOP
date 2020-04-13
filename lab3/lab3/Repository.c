#include "Repository.h"
#include <stdio.h>

magicStock createMagicStock()
{
	magicStock stock;
	stock.size = 0;
	stock.capacity = 100;
	return stock;
}

int getSize(magicStock* stock)
{
	return stock->size;
}

bool addMagicItem(magicStock* stock, magicItem newItem)
{
	if (stock->size == stock->capacity - 1)
	{
		//printf("Capacity was already reached!");
		return false;
	}
	if (exists(stock, newItem.catalogueNumber))
	{
		//printf("NO! *catalogue number already exists*");
		return false;
	}
	stock->items[stock->size] = newItem;
	stock->size++;
	return true;
}

bool removeMagicItem(magicStock* stock, int catalogueNumber)
{
	if (exists(stock, catalogueNumber) == false)
	{
		//printf("NO! *catalogue number does not exist*");
		return false;
	}
	int index = 0;
	while (getCatalogueNumber(&stock->items[index]) != catalogueNumber)
		index++;
	stock->items[index] = stock->items[stock->size - 1];
	stock->size--;
	return true;
}

bool updateMagicItem(magicStock* stock, magicItem updatedItem)
{
	if (exists(stock, updatedItem.catalogueNumber) == false)
	{
		//printf("NO! *catalogue number does not exist*");
		return false;
	}
	int index = 0;
	while (stock->items[index].catalogueNumber != updatedItem.catalogueNumber)
		index++;
	stock->items[index] = updatedItem;
	return true;
}

bool exists(magicStock* stock, int catalogueNumber)
{
	for (int index = 0; index < stock->size; index++)
		if (stock->items[index].catalogueNumber == catalogueNumber)
			return true;
	return false;
}

magicItem getMagicItem(magicStock* stock, int catalogueNumber)
{
	return stock->items[catalogueNumber];
}
