#pragma once
#include "Controller.h"

class RunicAltar {
private:
	Enchantment enchantment_;

	static void printMenuA();
	static void printMenuB();
	void printAllStatues();
	void printActiveStatues();
	void printFilteredStatues(std::string material, int age);
	void runBMode();
	void runAMode();

public:
	RunicAltar(const Enchantment& enchantment) : enchantment_(enchantment) {}
	void run();
};