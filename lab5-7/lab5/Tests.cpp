#include "Tests.h"
#include "UI.h"
#include <iostream>
#include <assert.h>

void getPowerWordName_vaidInput_assertTrue(GuardianStatue testStatue)
{
	assert(testStatue.getPowerWordName() == "cool statue");
}

void getMaterial_vaidInput_assertTrue(GuardianStatue testStatue)
{
	assert(testStatue.getMaterial() == "marble");
}

void getAge_vaidInput_assertTrue(GuardianStatue testStatue)
{
	assert(testStatue.getAge() == 237);
}

void getCorporealForm_vaidInput_assertTrue(GuardianStatue testStatue)
{
	assert(testStatue.getCorporealForm() == "mage");
}

void getPowerWordName_invaidInput_assertFalse(GuardianStatue testStatue)
{
	assert(!(testStatue.getPowerWordName() == "whatever statue"));
}

void getMaterial_invaidInput_assertFalse(GuardianStatue testStatue)
{
	assert(!(testStatue.getMaterial() == "stone"));
}

void getAge_invaidInput_assertFalse(GuardianStatue testStatue)
{
	assert(!(testStatue.getAge() == 542));
}

void getCorporealForm_invaidInput_assertFalse(GuardianStatue testStatue)
{
	assert(!(testStatue.getCorporealForm() == "knight"));
}

void testGuardianStatue()
{
	GuardianStatue testStatue("cool statue", "marble", 237, "mage");
	getPowerWordName_vaidInput_assertTrue(testStatue);
	getMaterial_vaidInput_assertTrue(testStatue);
	getAge_vaidInput_assertTrue(testStatue);
	getCorporealForm_vaidInput_assertTrue(testStatue);
	getPowerWordName_invaidInput_assertFalse(testStatue);
	getMaterial_invaidInput_assertFalse(testStatue);
	getAge_invaidInput_assertFalse(testStatue);
	getCorporealForm_invaidInput_assertFalse(testStatue);
}

void addStatue_validInput_added(Encyclopedia* testEncyclopedia)
{
	GuardianStatue testStatue("cool statue", "marble", 237, "mage");
	testEncyclopedia->addStatue(testStatue);
	assert(testEncyclopedia->getSize() == 1);
}

void addStatue_duplicate_notAdded(Encyclopedia* testEncyclopedia)
{
	GuardianStatue testStatue1("cool statue", "marble", 237, "mage");
	GuardianStatue testStatue2("cool statue", "stone", 256, "knight");
	testEncyclopedia->addStatue(testStatue1);
	testEncyclopedia->addStatue(testStatue2);
	assert(testEncyclopedia->getSize() == 1);
}

void removeStatue_existingStatue_removed(Encyclopedia* testEncyclopedia)
{
	GuardianStatue testStatue("cool statue", "marble", 237, "mage");
	testEncyclopedia->removeStatue(0);
	int statuePosition = testEncyclopedia->findStatuePositionByPoweName("cool statue");
	testEncyclopedia->removeStatue(statuePosition);
	assert(testEncyclopedia->getSize() == 0);
}

void removeStatue_nonexistingStatue_notRemoved(Encyclopedia* testEncyclopedia)
{
	GuardianStatue testStatue("cool statue", "marble", 237, "mage");
	testEncyclopedia->addStatue(testStatue);
	int statuePosition = testEncyclopedia->findStatuePositionByPoweName("not there statue");
	testEncyclopedia->removeStatue(statuePosition);
	assert(!(testEncyclopedia->getSize() == 0));
}

void updateStatue_existingStatue_updated(Encyclopedia* testEncyclopedia)
{
	GuardianStatue testStatue("cool statue", "marble", 237, "mage");
	testEncyclopedia->addStatue(testStatue);
	GuardianStatue testStatueUpdated("cool statue", "stone", 528, "knight");
	testEncyclopedia->updateStatue(testStatueUpdated.getPowerWordName(), testStatueUpdated);
	assert(testEncyclopedia->getAllStatues()[testEncyclopedia->findStatuePositionByPoweName("cool statue")].getMaterial() == "stone");
	//assert(testEncyclopedia->getAllStatues()[testEncyclopedia->findStatuePositionByPoweName("cool statue")].getAge() == 528);
	//assert(testEncyclopedia->getAllStatues()[testEncyclopedia->findStatuePositionByPoweName("cool statue")].getCorporealForm() == "knight");
}

void updateStatue_nonexistingStatue_notUpdated(Encyclopedia* testEncyclopedia)
{
	GuardianStatue testStatue("cool statue", "marble", 237, "mage");
	testEncyclopedia->addStatue(testStatue);
	GuardianStatue testStatueUpdated("not existing statue", "diamond", 741, "king");
	testEncyclopedia->updateStatue(testStatueUpdated.getPowerWordName(), testStatueUpdated);
	assert(!(testEncyclopedia->getAllStatues()[testEncyclopedia->findStatuePositionByPoweName(testStatue.getPowerWordName())].getMaterial() == "diamond"));
	//assert(!(testEncyclopedia->getAllStatues()[testEncyclopedia->findStatuePositionByPoweName("cool statue")].getAge() == 741));
	//assert(!(testEncyclopedia->getAllStatues()[testEncyclopedia->findStatuePositionByPoweName("cool statue")].getCorporealForm() == "king"));
}

void testRepository()
{
	Encyclopedia* testEncyclopedia = new Encyclopedia;
	addStatue_validInput_added(testEncyclopedia);
	addStatue_duplicate_notAdded(testEncyclopedia);
	removeStatue_existingStatue_removed(testEncyclopedia);
	updateStatue_existingStatue_updated(testEncyclopedia);
	updateStatue_nonexistingStatue_notUpdated(testEncyclopedia);
}

void addStatueEnchantment_validInput_assertTrue(Enchantment testEnchantment)
{
	assert(testEnchantment.addStatueEnchantment("cool statue", "marble", 562, "mage"));
}

void addStatueEnchantment_duplicate_assertFalse(Enchantment testEnchantment)
{
	assert(!(testEnchantment.addStatueEnchantment("cool statue", "stone", 23, "interesting")));
}

void remoneStatueEnchantment_existingStatue_removed(Enchantment testEnchantment)
{
	assert(testEnchantment.removeStatueEnchantment("cool statue"));
}

void remoneStatueEnchantment_nonexistingStatue_notRemoved(Enchantment testEnchantment)
{
	assert(!(testEnchantment.removeStatueEnchantment("cool statue")));
}

void updateStatueEnchantment_existingStatue_updated(Enchantment testEnchantment)
{
	testEnchantment.addStatueEnchantment("cool statue", "marble", 562, "mage");
	assert(testEnchantment.updateStatueEnchantment("cool statue", "stone", 23, "interesting"));
}

void updateStatueEnchantment_nonexistingStatue_notUpdated(Enchantment testEnchantment)
{
	assert(!(testEnchantment.updateStatueEnchantment("not there statue", "stone", 23, "interesting")));
}

void testController()
{
	Encyclopedia* testEncyclopedia = new Encyclopedia();
	Encyclopedia* testActiveStatues = new Encyclopedia();
	Enchantment testEnchantment(testEncyclopedia, testActiveStatues);
	addStatueEnchantment_validInput_assertTrue(testEnchantment);
	addStatueEnchantment_duplicate_assertFalse(testEnchantment);
	remoneStatueEnchantment_existingStatue_removed(testEnchantment);
	remoneStatueEnchantment_nonexistingStatue_notRemoved(testEnchantment);
	updateStatueEnchantment_existingStatue_updated(testEnchantment);
	updateStatueEnchantment_nonexistingStatue_notUpdated(testEnchantment);
}

void testAll()
{
	testGuardianStatue();
	testRepository();
	testController();
}
