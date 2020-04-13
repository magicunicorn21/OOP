#pragma once
#include "Repository.h"

class Enchantment {
private:
	Encyclopedia* encyclopedia_;
	Encyclopedia* activeStatues_;
	int currentStatuesPosition_;

public:
	Enchantment(Encyclopedia* encyclopedia, Encyclopedia* activeStatues) : encyclopedia_{ encyclopedia }, activeStatues_{ activeStatues }, currentStatuesPosition_{ -1 } {};
	bool addStatueEnchantment(std::string powerWordName, std::string material, int age, std::string corporealForm);
	bool removeStatueEnchantment(std::string powerWordName);
	bool updateStatueEnchantment(std::string powerWordName, std::string updatedMaterial, int updatedAge, std::string updatedCorporealForm);
	Encyclopedia* getEncyclopedia();
	Encyclopedia* getActiveStatues();
	DynamicVector<GuardianStatue> getAllStatues();
	DynamicVector<GuardianStatue> getAllActiveStatues();
	GuardianStatue next();
	void addActiveStatue(std::string powerWordName);
	DynamicVector<GuardianStatue> filterStatues(std::string powerWordName, int age);
};