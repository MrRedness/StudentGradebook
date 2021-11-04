#include "Add.hpp"
#include <iostream>
#include <vector>
#include "MrRed.hpp"
// #include <string>

Student Add::addStudent()
{
	using namespace std::chrono_literals;

	std::string name;
	int numberOfClasses;
	std::string nameClasses;

	std::cout << "What is the student's name?\n:";
	std::getline(std::cin, name);
	std::getline(std::cin, name);
	std::cout << "\n\nOk, how many classes is " + name + " taking?\n:";
	std::cin >> numberOfClasses;
	while (numberOfClasses <= 0 || numberOfClasses > 10)
	{
		std::cout << "\n\nWoah there, that's a strange number. Try something between 1 and 10.\n:";
		std::cin >> numberOfClasses;
	}
	bool invalidAnswer;
	do
	{
		invalidAnswer = false;
		std::cout << "\n\nWould you like to give each class a name? (type yes/no)\n:";
		std::cin >> nameClasses;
		if (stringEqualsIgnoreCase(nameClasses, "yes", "y"))
		{
			//auto namesOfClasses = new std::string[numberOfClasses];
			std::vector<std::string> namesOfClasses;
			std::cout << "\nPlease enter the name for each class or leave it blank\n";
			std::string input;
			std::getline(std::cin, input);
			for (int i = 0; i < numberOfClasses; i++)
			{
				std::cout << "\nClass " << i + 1 << "\n:";
				std::getline(std::cin, input);
				namesOfClasses.emplace_back(input);
			}
			//for (int i = 0; i < numberOfClasses; i++)
			//{
			//	std::cout << "\n" << namesOfClasses[i];
			//}
			std::cout << "\n\nStudent " << name << " successfully added!\n\n";
			return Student(name, numberOfClasses, namesOfClasses);
		}
		else if (stringEqualsIgnoreCase(nameClasses, "no", "n"))
		{
			std::cout << "\n\nStudent " << name << " successfully added!\n\n";
		}
		else
		{
			std::cout << "\nPlease type either \"yes\" or \"no\".";
			invalidAnswer = true;
		}
	} while (invalidAnswer);
	return Student(name, numberOfClasses);
}