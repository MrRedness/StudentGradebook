#include "Student.hpp"
#include "MrRed.hpp"
#include <chrono>
#include <thread>
#include <vector>

Student::Student(std::string_view name, int const& numberOfClasses)
	: name(name), numberOfClasses(numberOfClasses)
{
	for (int i = 0; i < numberOfClasses; i++) {
		namesOfClasses.emplace_back("");
	}
};
Student::Student(std::string_view name, int const& numberOfClasses, std::vector<std::string> const& namesOfClasses)
	: name(name), numberOfClasses(numberOfClasses), namesOfClasses(namesOfClasses) {};
Student::Student(std::string_view name, std::vector<std::string> const& namesOfClasses)
	: name(name), namesOfClasses(namesOfClasses), numberOfClasses(namesOfClasses.size()) {};

std::string Student::getName() const { return name; }

int Student::getNumberOfClasses() const { return numberOfClasses; }

std::string Student::getNameOfClass(int classNumber) const
{
	if (classNumber > 0 && classNumber <= numberOfClasses)
		return namesOfClasses.at(classNumber - 1);
	else
		return "Invalid Class Number";
}

int Student::getClassPeriod(std::string className) const
{
	for (int i = 0; i < numberOfClasses; i++)
	{
		if (stringEqualsIgnoreCase(namesOfClasses[i], className))
			return i;
	}
	return 0;
}

std::vector<std::string> Student::getNamesOfClasses() const { return namesOfClasses; }

void Student::setName(std::string_view newName) { this->name = newName; }

//void Student::setNumberOfClasses(int const& numberOfClasses) { 
//	this->numberOfClasses = numberOfClasses; 
//}

bool Student::setNameOfClass(int const& classPeriod, std::string_view newName)
{
	if (classPeriod <= 0 || classPeriod > numberOfClasses)
		return false;
	namesOfClasses[classPeriod] = newName;
	return true;
}

bool Student::setNameOfClass(std::string_view oldName, std::string_view newName)
{
	for (int i = 0; i < numberOfClasses; i++)
	{
		if (stringEqualsIgnoreCase(namesOfClasses[i], oldName))
		{
			namesOfClasses[i] = newName;
			return true;
		}
	}
	return false;
}

bool Student::setNamesOfClasses(std::vector<std::string> const& newNamesOfClasses)
{
	if (newNamesOfClasses.size() == numberOfClasses)
	{
		namesOfClasses = newNamesOfClasses;
		return true;
	}
	return false;
}

bool Student::addClass()
{
	if (numberOfClasses == 10)
		return false;
	numberOfClasses++;
	namesOfClasses.emplace_back("");
	return true;
}

bool Student::addClass(int const& classPeriod)
{
	if (numberOfClasses == 10 || classPeriod <= 0 || classPeriod > (numberOfClasses + 1))
		return false;
	numberOfClasses++;
	namesOfClasses.emplace(namesOfClasses.begin() + (classPeriod - 1), "");
	return true;
}

bool Student::addClass(std::string_view className)
{
	if (numberOfClasses == 10)
		return false;
	numberOfClasses++;
	namesOfClasses.emplace_back(className);
	return true;
}

bool Student::addClass(int const& classPeriod, std::string_view className)
{
	if (numberOfClasses == 10 || classPeriod <= 0 || classPeriod > (numberOfClasses + 1))
		return false;
	numberOfClasses++;
	namesOfClasses.emplace(namesOfClasses.begin() + (classPeriod - 1), className);
	return true;
}

bool Student::removeClass()
{
	if (numberOfClasses == 1)
		return false;
	numberOfClasses--;
	namesOfClasses.pop_back();
	return true;
}

bool Student::removeClass(int const& classPeriod)
{
	if (numberOfClasses == 1 || classPeriod <= 0 || classPeriod > numberOfClasses)
		return false;
	numberOfClasses--;
	namesOfClasses.erase(namesOfClasses.begin() + (classPeriod - 1));
	return true;
}

bool Student::removeClass(std::string_view className)
{
	if (numberOfClasses == 1)
		return false;
	numberOfClasses--;
	for (int i = 0; i < numberOfClasses; i++)
	{
		if (stringEqualsIgnoreCase(namesOfClasses[i], className))
		{
			namesOfClasses.erase(namesOfClasses.begin() + i);
			return true;
		}
	}
	return false;
}

std::ostream& operator<<(std::ostream& stream, Student const& student)
{
	stream << "\n\nStudent Name: " << student.getName() << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds{ 500 });
	stream << "\nNumber of classes " << student.getName() << " is taking: " << student.getNumberOfClasses() << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds{ 500 });
	stream << "\nThe names of those classes: " << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds{ 500 });
	for (std::string nameOfClass : student.getNamesOfClasses())
	{
		stream << "\n" << nameOfClass;
		std::this_thread::sleep_for(std::chrono::milliseconds{ 500 });
	}
	return stream;
}









