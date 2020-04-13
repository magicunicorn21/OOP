#pragma once
#include <iostream>

class GuardianStatue {
private:
	std::string powerWordName_;
	std::string material_;
	int age_;
	std::string corporealForm_;

public:
	GuardianStatue() {};
	GuardianStatue(std::string powerWordName, std::string material, int age, std::string corporealForm);
	std::string getPowerWordName();
	std::string getMaterial();
	int getAge();
	std::string getCorporealForm();
	std::string toString();
};