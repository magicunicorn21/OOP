#include "Tests.h"
#include "UI.h"
#include <iostream>
#include <fstream>
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

void toString_GuardianStatue_GuardianStatueIntoString(GuardianStatue testStatue)
{
	assert(testStatue.toString() == "cool statue, marble, 237, mage");
}

void equalOperator_equalStatue_true(GuardianStatue testStatue)
{
	GuardianStatue statueToCompare("cool statue", "marble", 237, "mage");
	assert(testStatue == statueToCompare);
}

void notEqualOperator_equalStatue_true(GuardianStatue testStatue)
{
	GuardianStatue statueToCompare("not cool statue", "something", 2647, "another");
	assert(testStatue != statueToCompare);
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
	toString_GuardianStatue_GuardianStatueIntoString(testStatue);
	equalOperator_equalStatue_true(testStatue);
	notEqualOperator_equalStatue_true(testStatue);
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

void writeToFile_multipleWrites_written(Encyclopedia* testEncyclopedia)
{
	GuardianStatue statue1("a", "skcbhf", 123, "kaudhse");
	GuardianStatue statue2("b", "sgfv", 234, "sejfg");
	GuardianStatue statue3("c", "kadhw", 743, "jefb");
	std::vector< GuardianStatue> statues;
	statues.push_back(statue1);
	statues.push_back(statue2);
	statues.push_back(statue3);
	testEncyclopedia->writeToFile("ok", statues);
	assert(testEncyclopedia->getSize() == 3);
}

void testRepository()
{
	Encyclopedia* testEncyclopedia = new Encyclopedia();
	testEncyclopedia->setPath("ok");
	addStatue_validInput_added(testEncyclopedia);
	addStatue_duplicate_notAdded(testEncyclopedia);
	removeStatue_existingStatue_removed(testEncyclopedia);
	removeStatue_nonexistingStatue_notRemoved(testEncyclopedia);
	updateStatue_existingStatue_updated(testEncyclopedia);
	updateStatue_nonexistingStatue_notUpdated(testEncyclopedia);
	writeToFile_multipleWrites_written(testEncyclopedia);
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

void next_nextObject_iterated(Enchantment testEnchantment)
{
	assert(testEnchantment.next() == testEnchantment.getAllStatues()[0]);
}

void addActiveStatue_existingStatue_added(Enchantment testEnchantment)
{
	testEnchantment.addActiveStatue("cool statue");
	assert(testEnchantment.getAllActiveStatues()[0].getPowerWordName() == "cool statue");
}

void filterStatues_existingStatueMaterialAge_found(Enchantment testEnchantment)
{
	std::vector<GuardianStatue> statues = testEnchantment.filterStatues("stone", 25);
	assert(statues.size() == 1);
}

void filterStatues_existingStatueBadMaterialGoodAge_found(Enchantment testEnchantment)
{
	std::vector<GuardianStatue> statues = testEnchantment.filterStatues("marble", 25);
	assert(statues.size() == 1);
}

void testController()
{
	Encyclopedia* testEncyclopedia = new Encyclopedia();
	Encyclopedia* testActiveStatues = new Encyclopedia();
	Enchantment testEnchantment(testEncyclopedia, testActiveStatues);
	testEnchantment.setPath("blabla");
	testActiveStatues->setPath("newOne");
	addStatueEnchantment_validInput_assertTrue(testEnchantment);
	addStatueEnchantment_duplicate_assertFalse(testEnchantment);
	remoneStatueEnchantment_existingStatue_removed(testEnchantment);
	remoneStatueEnchantment_nonexistingStatue_notRemoved(testEnchantment);
	updateStatueEnchantment_existingStatue_updated(testEnchantment);
	updateStatueEnchantment_nonexistingStatue_notUpdated(testEnchantment);
	next_nextObject_iterated(testEnchantment);
	addActiveStatue_existingStatue_added(testEnchantment);
	filterStatues_existingStatueMaterialAge_found(testEnchantment);
	filterStatues_existingStatueBadMaterialGoodAge_found(testEnchantment);
}

void testAll()
{
	testGuardianStatue();
	testRepository();
	testController();
}
