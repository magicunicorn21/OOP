#pragma once

typedef struct
{
	int catalogueNumber;
	char state[50];
	char type[50];
	int value;
} magicItem;

magicItem createMagicItem(int catalogueNumber, char state[], char type[], int value);
int getCatalogueNumber(magicItem* item);
char* getState(magicItem* item);
char* getType(magicItem* item);
int getValue(magicItem* item);
//void toString(magicItem item, char stringItem[]);