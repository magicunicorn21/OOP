#include "UI.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

RuneView createRuneView(RuneCaller* runeCaller)
{
	RuneView runeView;
	runeView.runeCaller = runeCaller;
	return runeView;
}

void printMagicItem(magicItem item)
{
	printf("catalogue number: %d, state: %s, type: %s, value: %d\n",
		getCatalogueNumber(&item), getState(&item), getType(&item), getValue(&item));
}

void printMagicStock(magicStock stock)
{
	for (int index = 0; index < stock.size; index++)
		printMagicItem(stock.items[index]);
}

void runRune(RuneView* runeView)
{
	char command[300];
	char delimitatorCommand[] = " ";
	char delimitatorAttributes[] = ", ";
	bool runVariable = true;
	while (runVariable)
	{
		printf("Write your command: ");
		gets(command);
		char* commandParser = strtok(command, delimitatorCommand);
		if (strcmp(commandParser, "exit") == 0)
		{
			runVariable = false;
		}
		else if(strcmp(commandParser, "list") == 0)
		{
			commandParser = strtok(NULL, delimitatorAttributes);
			if (commandParser == NULL) {
				magicStock* items = runeList(runeView->runeCaller);
				printMagicStock(*items);
			}
			else if (isdigit(commandParser[0]) != 0)
			{
				magicStock filteredItems = runeFilterSmallerThanValue(runeView->runeCaller, atoi(commandParser));
				printMagicStock(filteredItems);
			}
			else
			{
				magicStock filteredItems = runeFilter(runeView->runeCaller, commandParser);
				printMagicStock(filteredItems);
			}
		}
		else if (strcmp(commandParser, "add") == 0)
		{
			char state[100], type[100];
			int catalogueNumber, value;
			commandParser = strtok(NULL, delimitatorAttributes);
			catalogueNumber = atoi(commandParser);
			commandParser = strtok(NULL, delimitatorAttributes);
			strcpy(state, commandParser);
			commandParser = strtok(NULL, delimitatorAttributes);
			strcpy(type, commandParser);
			commandParser = strtok(NULL, delimitatorAttributes);
			value = atoi(commandParser);
			if (!runeAdd(runeView->runeCaller, catalogueNumber, state, type, value))
				printf("NO!!  --invalid data\n");
		}
		else if (strcmp(commandParser, "update") == 0)
		{
			char newState[100], newType[100];
			int catalogueNumber, newValue;
			commandParser = strtok(NULL, delimitatorAttributes);
			catalogueNumber = atoi(commandParser);
			commandParser = strtok(NULL, delimitatorAttributes);
			strcpy(newState, commandParser);
			commandParser = strtok(NULL, delimitatorAttributes);
			strcpy(newType, commandParser);
			commandParser = strtok(NULL, delimitatorAttributes);
			newValue = atoi(commandParser);
			if (!runeUpdate(runeView->runeCaller, catalogueNumber, newState, newType, newValue))
				printf("NO!!  --invalid data\n");
		}
		else if (strcmp(commandParser, "delete") == 0)
		{
			int catalogueNumber;
			commandParser = strtok(NULL, delimitatorAttributes);
			catalogueNumber = atoi(commandParser);
			if (!runeRemove(runeView->runeCaller, catalogueNumber))
				printf("NO!!  --invalid catalogue number\n");
		}
		else
		{
			printf("Invalid command!!\n");
		}
	}
}
