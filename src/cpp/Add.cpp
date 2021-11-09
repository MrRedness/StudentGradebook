#include "Add.hpp"
#include <iostream>
#include <vector>
#include <chrono>
#include "MrRed.hpp"
#include <string>

Student Add::addStudent()
{
	using namespace std::chrono_literals;

	std::string name;
	int numberOfClasses;
	std::string nameClassesString;
	bool nameClassesBool;
	std::string gradeClassesString;

	std::cout << "What is the student's name?\n:";
	std::getline(std::cin, name);
	std::getline(std::cin, name);
	std::cout << "\n\nOk, how many classes is " + name + " taking?\n:";
	numberOfClasses = cinInt(1, 10);
	std::vector<Class> classes;
	for (int i = 0; i < numberOfClasses; i++)
		classes.emplace_back(Class{"", -1});
	bool invalidAnswer;
	do
	{
		invalidAnswer = false;
		std::cout << "\n\nWould you like to give each class a name? (type yes/no)\n:";
		std::cin >> nameClassesString;
		if (stringEqualsOneOfTheFollowingIgnoreCase(nameClassesString, {"yes", "y"}))
		{
			nameClassesBool = true;
			std::cout << "\nPlease enter the name for each class or leave it blank\n";
			std::string input;
			std::getline(std::cin, input);
			for (int i = 0; i < numberOfClasses; i++)
			{
				std::cout << "\nClass " << i + 1 << "\n:";
				std::getline(std::cin, input);
				classes[i].name = input;
			}
			// for (unsigned int i = 0; i < numberOfClasses; i++)
			//{
			//	std::cout << "\n" << namesOfClasses[i];
			// }
		}
		else if (stringEqualsOneOfTheFollowingIgnoreCase(nameClassesString, {"no", "n"}))
		{
			nameClassesBool = false;
		}
		else
		{
			std::cout << "\nPlease type either \"yes\" or \"no\".";
			invalidAnswer = true;
		}
	} while (invalidAnswer);
	do
	{
		invalidAnswer = false;
		std::cout << "\n\nWould you like to enter grades for " + name + "'s classes? (type yes/no)\n:";
		std::cin >> gradeClassesString;
		if (stringEqualsOneOfTheFollowingIgnoreCase(gradeClassesString, {"yes", "y"}))
		{
			std::cout << "\nPlease enter the grade for each class (between 0 and 100) or type -1 for no grade.\n";
			std::string stringInput;
			int gradeInput;
			std::getline(std::cin, stringInput);
			for (int i = 0; i < numberOfClasses; i++)
			{
				std::cout << "\nClass " << i + 1 << "\n:";
				gradeInput = cinInt(-1, 100);
				classes[i].grade = gradeInput;
			}
			// for (unsigned int i = 0; i < numberOfClasses; i++)
			//{
			//	std::cout << "\n" << namesOfClasses[i];
			// }
			std::cout << "\n\nStudent " << name << " successfully added!\n\n";
			return Student(name, nameClassesBool, true, classes);
		}
		else if (stringEqualsOneOfTheFollowingIgnoreCase(gradeClassesString, {"no", "n"}))
		{
			std::cout << "\n\nStudent " << name << " successfully added!\n\n";
			return Student(name, nameClassesBool, false, classes);
		}
		else
		{
			std::cout << "\nPlease type either \"yes\" or \"no\".";
			invalidAnswer = true;
		}
	} while (invalidAnswer);
	return Student(name, false, false, classes);
}