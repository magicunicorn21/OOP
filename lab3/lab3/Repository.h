#pragma once
#include "Domain.h"
#include <stdbool.h>

typedef struct
{
	magicItem items[100];
	int size;
	int capacity;
} magicStock;

magicStock createMagicStock();
magicItem getMagicItem(magicStock* stock, int catalogueNumber);
int getSize(magicStock* stock);
bool addMagicItem(magicStock* stock, magicItem newItem);
bool removeMagicItem(magicStock* stock, int catalogueNumber);
bool updateMagicItem(magicStock* stock, magicItem updatedItem);
bool exists(magicStock* stock, int catalogueNumber);
//magicStock filterType(magicStock* stock, char type[]);