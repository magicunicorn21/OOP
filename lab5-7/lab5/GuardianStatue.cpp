#include "GuardianStatue.h"
#include <string>
#include <vector>
#include <sstream>

#define inputPowerWordName 0
#define inputMaterial 1
#define inputAge 2
#define inputCorporealForm 3

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

bool GuardianStatue::operator==(GuardianStatue& statue)
{
	return (powerWordName_ == statue.getPowerWordName() &&
		material_ == statue.getMaterial() &&
		age_ == statue.getAge() &&
		corporealForm_ == statue.getCorporealForm());
}

bool GuardianStatue::operator!=(GuardianStatue& statue)
{
	return !(powerWordName_ == statue.getPowerWordName() &&
		material_ == statue.getMaterial() &&
		age_ == statue.getAge() &&
		corporealForm_ == statue.getCorporealForm());
}

std::istream& operator>>(std::istream& inputStream, GuardianStatue& statue)
{
	std::string attributes;
	std::getline(inputStream, attributes);
	std::vector<std::string> splittedCommand;
	std::stringstream attributesStream(attributes);
	std::string attribute;
	while (std::getline(attributesStream, attribute, ','))
		splittedCommand.push_back(attribute);
	statue.powerWordName_ = splittedCommand[inputPowerWordName];
	statue.material_ = splittedCommand[inputMaterial];
	statue.age_ = std::stoi(splittedCommand[inputAge]);
	statue.corporealForm_ = splittedCommand[inputCorporealForm];
	return inputStream;
}

std::ostream& operator<<(std::ostream& outputStream, GuardianStatue& statue)
{
	outputStream << statue.getPowerWordName() << "," <<
		statue.getMaterial() << "," <<
		statue.getAge() << "," <<
		statue.getCorporealForm();
	return outputStream;
}
