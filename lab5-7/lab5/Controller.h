#pragma once
#include "Repository.h"

class Enchantment {
private:
	Encyclopedia* encyclopedia_;
	Encyclopedia* activeStatues_;
	int currentStatuesPosition_;
	std::string path_;

public:
	Enchantment(Encyclopedia* encyclopedia, Encyclopedia* activeStatues) : encyclopedia_{ encyclopedia }, activeStatues_{ activeStatues }, currentStatuesPosition_{ -1 } {};
	bool addStatueEnchantment(std::string powerWordName, std::string material, int age, std::string corporealForm);
	bool removeStatueEnchantment(std::string powerWordName);
	bool updateStatueEnchantment(std::string powerWordName, std::string updatedMaterial, int updatedAge, std::string updatedCorporealForm);
	Encyclopedia* getEncyclopedia() { return encyclopedia_; };
	Encyclopedia* getActiveStatues() { return activeStatues_; };
	std::vector<GuardianStatue> getAllStatues() { return encyclopedia_->getAllStatues(); };
	std::vector<GuardianStatue> getAllActiveStatues() { return activeStatues_->getAllStatues(); };
	GuardianStatue next();
	void addActiveStatue(std::string powerWordName);
	std::vector<GuardianStatue> filterStatues(std::string material, int age);
	void setPath(std::string path);
};