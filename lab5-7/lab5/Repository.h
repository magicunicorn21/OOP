#pragma once
#include "GuardianStatue.h"
#include <vector>

class Encyclopedia {
	std::string path_;

public:
	Encyclopedia() {}
	void setPath(std::string path) { path_ = path; }
	void addStatue(GuardianStatue& newStatue);
	void removeStatue(int position);
	void updateStatue(std::string powerName, const GuardianStatue& updatedStatue);
	std::vector<GuardianStatue> getAllStatues();
	int findStatuePositionByPoweName(std::string powerName);
	int getSize();
	void readFromFile(std::string path, std::vector<GuardianStatue>& statues);
	void writeToFile(std::string path, std::vector<GuardianStatue>& statues);
	friend std::ostream& operator<<(std::ostream& outputStream, std::vector<GuardianStatue>& statues);
};