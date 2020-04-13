#include "UI.h"
#include "Tests.h"

int main()
{
	//testAll();
	Encyclopedia* encyclopedia = new Encyclopedia();
	Encyclopedia* activeStatues = new Encyclopedia();
	Enchantment enchantment(encyclopedia, activeStatues);
	RunicAltar runeAltar(enchantment);
	runeAltar.run();
	return 0;
}