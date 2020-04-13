#pragma once
#include "GuardianStatue.h"
#include "DynamicVector.h"

class Encyclopedia {
private:
	DynamicVector<GuardianStatue> statues_;

public:
	Encyclopedia() {}
	void addStatue(GuardianStatue& newStatue);
	void removeStatue(int position);
	void updateStatue(std::string powerName, const GuardianStatue& updatedStatue);
	DynamicVector<GuardianStatue> getAllStatues() const { return statues_; };
	int findStatuePositionByPoweName(std::string powerName);
	int getSize();
};