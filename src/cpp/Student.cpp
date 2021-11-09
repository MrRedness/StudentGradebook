#include "Student.hpp"
#include "MrRed.hpp"
#include <chrono>
#include <thread>
#include <vector>

// Student::Student(std::string_view name, int const &numberOfClasses)
// 	: name(name), hasNamesForClasses(false)
// {
// 	for (unsigned int i = 0; i < numberOfClasses; i++)
// 	{
// 		classes.emplace_back(Class{"", -1});
// 	}
// }
// Student::Student(std::string_view name, int const &numberOfClasses, std::vector<std::string> const &namesOfClasses)
// 	: name(name), hasNamesForClasses(true)
// {
// 	for (unsigned int i = 0; i < numberOfClasses; i++)
// 	{
// 		classes.emplace_back(Class{namesOfClasses[i], -1});
// 	}
// }
// Student::Student(std::string_view name, std::vector<std::string> const &namesOfClasses)
// 	: name(name), hasNamesForClasses(true)
// {
// 	for (unsigned int i = 0; i < (namesOfClasses.size() - 1); i++)
// 	{
// 		classes.emplace_back(Class{namesOfClasses[i], -1});
// 	}
// }
Student::Student(std::string_view name, bool const &hasNamesForClasses, bool const &hasGradesForClasses, std::vector<Class> const &classes)
	: name(name), hasNamesForClasses(hasNamesForClasses), hasGradesForClasses(hasGradesForClasses), classes(classes){};

std::string Student::getName() const
{
	return name;
}

int Student::getNumberOfClasses() const { return classes.size(); }

std::string Student::getNameOfClass(int const &classNumber) const
{
	if (classNumber > 0 && classNumber <= classes.size())
		return classes[classNumber - 1].name;
	else
		return "Invalid Class Number";
}

int Student::getClassPeriod(std::string_view className) const
{
	for (unsigned int i = 0; i < classes.size(); i++)
	{
		if (stringEqualsIgnoreCase(classes[i].name, className))
			return i + 1;
	}
	return 0;
}

bool Student::getHasNamesForClasses() const { return hasNamesForClasses; }

std::vector<std::string> Student::getNamesOfClasses() const
{
	std::vector<std::string> namesOfClasses;
	for (unsigned int i = 0; i < (classes.size() - 1); i++)
		namesOfClasses.emplace_back(classes[i].name);
	return namesOfClasses;
}

void Student::setName(std::string_view newName) { this->name = newName; }

// void Student::setNumberOfClasses(int const& numberOfClasses) {
//	this->numberOfClasses = numberOfClasses;
// }

bool Student::setNameOfClass(int const &classPeriod, std::string_view newName)
{
	if (classPeriod <= 0 || classPeriod > classes.size())
		return false;
	classes[classPeriod - 1].name = newName;
	return true;
}

bool Student::setNameOfClass(std::string_view oldName, std::string_view newName)
{
	for (unsigned int i = 0; i < classes.size(); i++)
	{
		if (stringEqualsIgnoreCase(classes[i].name, oldName))
		{
			classes[i].name = newName;
			return true;
		}
	}
	return false;
}

bool Student::setNamesOfClasses(std::vector<std::string> const &newNamesOfClasses)
{
	int s = newNamesOfClasses.size();
	if (s == classes.size())
	{
		for (int i = 0; i < s; i++)
			classes[i].name = newNamesOfClasses[i];
		return true;
	}
	return false;
}

bool Student::addClass()
{
	if (classes.size() == 10)
		return false;
	classes.emplace_back(Class{"", -1});
	return true;
}

bool Student::addClass(int const &classPeriod)
{
	if (classes.size() == 10 || classPeriod <= 0 || classPeriod > (classes.size() + 1))
		return false;
	classes.emplace(classes.begin() + (classPeriod - 1), Class{"", -1});
	return true;
}

bool Student::addClass(std::string_view className)
{
	if (classes.size() == 10)
		return false;
	classes.emplace(classes.end() + 1, Class{std::string(className), -1});
	return true;
}

bool Student::addClass(int const &classPeriod, std::string_view className)
{
	if (classes.size() == 10 || classPeriod <= 0 || classPeriod > (classes.size() + 1))
		return false;
	classes.emplace(classes.begin() + (classPeriod - 1), Class{std::string(className), -1});
	return true;
}

bool Student::removeClass()
{
	if (classes.size() == 1)
		return false;
	classes.pop_back();
	return true;
}

bool Student::removeClass(int const &classPeriod)
{
	if (classes.size() == 1 || classPeriod <= 0 || classPeriod > classes.size())
		return false;
	classes.erase(classes.begin() + (classPeriod - 1));
	return true;
}

bool Student::removeClass(std::string_view className)
{
	if (classes.size() == 1)
		return false;
	for (int i = 0; i < classes.size(); i++)
	{
		if (stringEqualsIgnoreCase(classes[i].name, className))
		{
			classes.erase(classes.begin() + i);
			return true;
		}
	}
	return false;
}

std::ostream &operator<<(std::ostream &stream, Student const &student)
{
	stream << "\n\nStudent Name: " << student.getName() << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds{500});
	stream << "\nNumber of classes " << student.getName() << " is taking: " << student.getNumberOfClasses() << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds{500});
	if (student.getHasNamesForClasses())
	{
		stream << "\nThe names of those classes: " << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds{500});
		for (std::string nameOfClass : student.getNamesOfClasses())
		{
			stream << "\n"
				   << nameOfClass;
			std::this_thread::sleep_for(std::chrono::milliseconds{500});
		}
	}
	return stream;
}
