#pragma once
#include "Controller.h"

typedef struct {
	RuneCaller* runeCaller;
}RuneView;

RuneView createRuneView(RuneCaller* runeCaller);
void runRune(RuneView* runeView);
void printMagicItem(magicItem item);