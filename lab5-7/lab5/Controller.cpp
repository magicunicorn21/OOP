#include "Controller.h"
#include <string>

bool Enchantment::addStatueEnchantment(std::string powerWordName, std::string material, int age, std::string corporealForm)
{
    GuardianStatue statueToAdd(powerWordName, material, age, corporealForm);
    if (encyclopedia_->findStatuePositionByPoweName(powerWordName) != -1)
        return false;
    encyclopedia_->addStatue(statueToAdd);
    return true;
}

bool Enchantment::removeStatueEnchantment(std::string powerWordName)
{
    int statuePosition = encyclopedia_->findStatuePositionByPoweName(powerWordName);
    if (statuePosition == -1)
        return false;
    encyclopedia_->removeStatue(statuePosition);
    return true;
}

bool Enchantment::updateStatueEnchantment(std::string powerWordName, std::string updatedMaterial, int updatedAge, std::string updatedCorporealForm)
{
    int statuePosition = encyclopedia_->findStatuePositionByPoweName(powerWordName);
    if (statuePosition == -1)
        return false;
    GuardianStatue updatedStatue(powerWordName, updatedMaterial, updatedAge, updatedCorporealForm);
    encyclopedia_->updateStatue(powerWordName, updatedStatue);
    return true;
}

GuardianStatue Enchantment::next()
{
    currentStatuesPosition_++;
    if (currentStatuesPosition_ == encyclopedia_->getSize())
        currentStatuesPosition_ = 0;
    GuardianStatue statue = encyclopedia_->getAllStatues()[currentStatuesPosition_];
    return statue;
}

void Enchantment::addActiveStatue(std::string powerWordName)
{
    int statuePosition = encyclopedia_->findStatuePositionByPoweName(powerWordName);
    GuardianStatue statueToSave = encyclopedia_->getAllStatues()[statuePosition];
    activeStatues_->addStatue(statueToSave);
}

std::vector<GuardianStatue> Enchantment::filterStatues(std::string material, int age)
{
    std::vector<GuardianStatue> allStatues = encyclopedia_->getAllStatues();
    std::vector<GuardianStatue> filteredStatues;
    for (GuardianStatue& statue : allStatues)
        if (statue.getAge() < age && statue.getMaterial() == material)
            filteredStatues.push_back(statue);
    if (filteredStatues.size() == 0)
        for (GuardianStatue& statue : allStatues)
            if (statue.getAge() < age)
                filteredStatues.push_back(statue);
    return filteredStatues;
}

void Enchantment::setPath(std::string path)
{
    path_ = path;
    encyclopedia_->setPath(path);
}
