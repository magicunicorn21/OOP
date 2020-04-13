#include "GuardianStatue.h"
#include <string>

GuardianStatue::GuardianStatue(std::string powerWordName, std::string material, int age, std::string corporealForm)
{
	powerWordName_ = powerWordName;
	material_ = material;
	age_ = age;
	corporealForm_ = corporealForm;
}

std::string GuardianStatue::getPowerWordName()
{
	return powerWordName_;
}

std::string GuardianStatue::getMaterial()
{
	return material_;
}

int GuardianStatue::getAge()
{
	return age_;
}

std::string GuardianStatue::getCorporealForm()
{
	return corporealForm_;
}

std::string GuardianStatue::toString()
{
	std::string statueString = "";
	std::string ageString = std::to_string(age_);
	statueString += powerWordName_ + ", ";
	statueString += material_ + ", ";
	statueString += ageString + ", ";
	statueString += corporealForm_;
	return statueString;
}
