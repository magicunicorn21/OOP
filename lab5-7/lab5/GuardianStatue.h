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
	~GuardianStatue() {}
	std::string getPowerWordName();
	std::string getMaterial();
	int getAge();
	std::string getCorporealForm();
	std::string toString();
	bool operator==(GuardianStatue& statue);
	bool operator!=(GuardianStatue& statue);
	friend std::istream& operator>>(std::istream& input, GuardianStatue& statue);
	friend std::ostream& operator<<(std::ostream& output, GuardianStatue& statue);
};