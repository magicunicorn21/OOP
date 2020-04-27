#include "Repository.h"
#include <fstream>
#include <stdio.h>

void Encyclopedia::addStatue(GuardianStatue& newStatue)
{
	std::vector<GuardianStatue> statues;
	readFromFile(path_, statues);
	if (findStatuePositionByPoweName(newStatue.getPowerWordName()) != -1)
		return;
	statues.push_back(newStatue);
	writeToFile(path_, statues);
}

void Encyclopedia::removeStatue(int position)
{
	std::vector<GuardianStatue> statues;
	readFromFile(path_, statues);
	if (position == -1)
		return;
	statues.erase(statues.begin() + position);
	writeToFile(path_, statues);
}

void Encyclopedia::updateStatue(std::string powerName, const GuardianStatue& updatedStatue)
{
	std::vector<GuardianStatue> statues;
	readFromFile(path_, statues);
	int positionStatue = findStatuePositionByPoweName(powerName);
	if (positionStatue == -1)
		return;
	statues.erase(statues.begin() + positionStatue);
	statues.insert(statues.begin() + positionStatue, updatedStatue);
	writeToFile(path_, statues);
}

std::vector<GuardianStatue> Encyclopedia::getAllStatues()
{
	std::vector<GuardianStatue> statues;
	readFromFile(path_, statues);
	return statues;
}

int Encyclopedia::findStatuePositionByPoweName(std::string powerName)
{
	std::vector<GuardianStatue> statues;
	readFromFile(path_, statues);
	int searchIndex = 0;
	for (GuardianStatue& element : statues)
	{
		if (element.getPowerWordName() == powerName)
			return searchIndex;
		searchIndex += 1;
	}
	return -1;
}

int Encyclopedia::getSize()
{
	std::vector<GuardianStatue> statues;
	readFromFile(path_, statues);
	return statues.size();
}

void Encyclopedia::readFromFile(std::string path, std::vector<GuardianStatue>& statues)
{
	std::ifstream fileToReadFrom(path);
	if (!fileToReadFrom.is_open())
	{
		std::fstream newFile(path);
		newFile.close();
		return;
	}
	GuardianStatue statue;
	if (!(fileToReadFrom.peek() == std::ifstream::traits_type::eof()))
		while (!fileToReadFrom.eof())
		{
			fileToReadFrom >> statue;
			statues.push_back(statue);
		}
	fileToReadFrom.close();
}

void Encyclopedia::writeToFile(std::string path, std::vector<GuardianStatue>& statues)
{
	std::ofstream fileToWriteTo(path);
	if (statues.size() > 0)
	{
		fileToWriteTo << statues[0];
		statues.erase(statues.begin());
		for (auto statue : statues)
		{
			fileToWriteTo << std::endl;
			fileToWriteTo << statue;
		}
		
	}
	else
	fileToWriteTo.close();
}


