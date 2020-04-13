#include "Repository.h"

void Encyclopedia::addStatue(GuardianStatue& newStatue)
{
	if (findStatuePositionByPoweName(newStatue.getPowerWordName()) != -1)
		return;
	statues_.add(newStatue);
}

void Encyclopedia::removeStatue(int position)
{
	if (position == -1)
		return;
	statues_.remove(position);
}

void Encyclopedia::updateStatue(std::string powerName, const GuardianStatue& updatedStatue)
{
	int positionStatue = findStatuePositionByPoweName(powerName);
	if (positionStatue == -1)
		return;
	statues_.update(positionStatue, updatedStatue);
}

int Encyclopedia::findStatuePositionByPoweName(std::string powerName)
{
	int searchIndex = 0;
	while (searchIndex < getSize())
	{
		if (statues_[searchIndex].getPowerWordName() == powerName)
			return searchIndex;
		searchIndex++;
	}
	return -1;
}

int Encyclopedia::getSize()
{
	return statues_.getSize();
}
