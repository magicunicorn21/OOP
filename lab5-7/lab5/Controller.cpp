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

Encyclopedia* Enchantment::getEncyclopedia()
{
    return encyclopedia_;
}

Encyclopedia* Enchantment::getActiveStatues()
{
    return activeStatues_;
}

DynamicVector<GuardianStatue> Enchantment::getAllStatues()
{
    return encyclopedia_->getAllStatues();
}

DynamicVector<GuardianStatue> Enchantment::getAllActiveStatues()
{
    return activeStatues_->getAllStatues();
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

DynamicVector<GuardianStatue> Enchantment::filterStatues(std::string powerWordName, int age)
{
    DynamicVector<GuardianStatue> allStatues = encyclopedia_->getAllStatues();
    DynamicVector<GuardianStatue> filteredStatues;// = new DynamicVector<GuardianStatue>(encyclopedia_->getSize());
    for (int index = 0; index < allStatues.getSize(); index++)
        if (allStatues[index].getAge() < age && allStatues[index].getPowerWordName() == powerWordName)
            filteredStatues.add(allStatues[index]);
    if (filteredStatues.getSize() == 0)
        for (int index = 0; index < allStatues.getSize(); index++)
            if (allStatues[index].getAge() < age)
                filteredStatues.add(allStatues[index]);
    return filteredStatues;
}
