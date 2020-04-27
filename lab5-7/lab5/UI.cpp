#include "UI.h"
#include <sstream>
#include <vector>

#define commandParameter 0
#define pathParameter 1

using namespace std;

void RunicAltar::printMenuA()
{
	std::cout << "Possible runes:" << std::endl;
	std::cout << "\tmode X (A - full fledged mages / B - apprentices)" << std::endl;
	std::cout << "\tadd powerWordName, material, age, corporealForm" << std::endl;
	std::cout << "\tupdate powerWordName, newMaterial, newAge, newCorporealForm" << std::endl;
	std::cout << "\tdelete powerWordName" << std::endl;
	std::cout << "\tlist" << std::endl;
	std::cout << "\texit" << std::endl;
}

void RunicAltar::printMenuB()
{
    std::cout << "Possible runes:" << std::endl;
    std::cout << "\tmode X (A - full fledged mages / B - apprentices)" << std::endl;
    std::cout << "\tnext" << std::endl;
    std::cout << "\tsave powerWordName" << std::endl;
    std::cout << "\tlist material, age" << std::endl;
    std::cout << "\tmylist" << std::endl;
}

std::vector<std::string> splitCommand(std::string command)
{

    std::stringstream original(command);
    std::string partOfCommand;
    std::vector<std::string> splitted;
    std::getline(original, partOfCommand, ' ');
    splitted.push_back(partOfCommand);
    while (std::getline(original, partOfCommand, ','))
        splitted.push_back(partOfCommand);
    return splitted;
}

void RunicAltar::printAllStatues()
{
    std::vector<GuardianStatue> statues = enchantment_.getAllStatues();
    for (GuardianStatue& statue : statues)
        std::cout << statue.toString() << std::endl;
}

void RunicAltar::printActiveStatues()
{
    std::vector<GuardianStatue> statues = enchantment_.getAllActiveStatues();
    for (GuardianStatue& statue : statues)
        std::cout << statue.toString() << std::endl;
}

void RunicAltar::printFilteredStatues(std::string material, int age)
{
    std::vector<GuardianStatue> statues = enchantment_.filterStatues(material, age);
    for (GuardianStatue& statue : statues)
        std::cout << statue.toString() << std::endl;
}

void RunicAltar::runAMode()
{
    int theCommand = 0, powerName = 1, material = 2, age = 3, form = 4, mode = 1;
    std::string command;
    while (true)
    {
        printMenuA();
        getline(cin, command);
        std::vector<std::string> splittedCommand = splitCommand(command);
        if (splittedCommand[theCommand] == "exit")
            return;
        else if (splittedCommand[theCommand] == "mode" && splittedCommand[mode] == "B")
        {
            runBMode();
            return;
        }
        else if (splittedCommand[theCommand] == "add")
            enchantment_.addStatueEnchantment(splittedCommand[powerName], splittedCommand[material], stoi(splittedCommand[age]), splittedCommand[form]);
        else if (splittedCommand[theCommand] == "delete")
            enchantment_.removeStatueEnchantment(splittedCommand[powerName]);
        else if (splittedCommand[theCommand] == "update")
            enchantment_.updateStatueEnchantment(splittedCommand[powerName], splittedCommand[material], stoi(splittedCommand[age]), splittedCommand[form]);
        else if (splittedCommand[theCommand] == "list")
            printAllStatues();
        else
            cout << "Invalid command!" << endl;
    }
}

void RunicAltar::runBMode()
{
    int theCommand = 0, powerName = 1, material = 1, age = 2, mode = 1;
    std::string command;
    while (true)
    {
        printMenuB();
        getline(cin, command);
        std::vector<std::string> splittedCommand = splitCommand(command);
        if (splittedCommand[theCommand] == "exit")
            return;
        else if (splittedCommand[theCommand] == "mode" && splittedCommand[mode] == "A")
        {
            runAMode();
            return;
        }
        else if (splittedCommand[theCommand] == "next")
        {
            GuardianStatue nextStatue = enchantment_.next();
            cout << nextStatue.toString() << endl;
        }
        else if (splittedCommand[theCommand] == "save")
            enchantment_.addActiveStatue(splittedCommand[powerName]);
        else if (splittedCommand[theCommand] == "list")
            printFilteredStatues(splittedCommand[material], stoi(splittedCommand[age]));
        else if (splittedCommand[theCommand] == "mylist")
            printActiveStatues();
        else
            cout << "Invalid command!" << endl;
    }
}

void RunicAltar::run()
{
    std::string mode, path;
    bool modeChosen = false;
    bool pathChosen = false;
    while (!pathChosen)
    {
        std::cout << "Choose path: " << endl;
        std::getline(std::cin, path);
        vector<string> splittedCommand = splitCommand(path);
        if (path == "exit")
        {
            pathChosen = true;
            modeChosen = true;
        }
        else if (splittedCommand[commandParameter] == "fileLocation")
        {
            if (splittedCommand.size() > 1)
            {
                pathChosen = true;
                enchantment_.setPath(splittedCommand[pathParameter]);
            }
        }
        else
            cout << "Invalid command!" << endl;
    }
    while (!modeChosen)
    {
        std::cout << "Choose mode (A - full fledged mages / B - apprentices): " << endl;
        std::getline(std::cin, mode);
        if (mode == "mode A")
        {
            runAMode();
            modeChosen = true;
        }
        else if (mode == "mode B")
        {
            runBMode();
            modeChosen = true;
        }
        else if (mode == "exit")
            modeChosen = true;
        else
            cout << "Invalid mode!" << endl;
    }
}
