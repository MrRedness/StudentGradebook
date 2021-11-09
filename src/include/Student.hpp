#pragma once
#include <iostream>
#include <vector>
#include <set>
//#include <string_view>

struct Class
{
	std::string name;
	double grade;
};

class Student
{
private:
	std::string name;
	// unsigned int numberOfClasses;
	bool hasNamesForClasses;
	bool hasGradesForClasses;
	// std::vector<std::string> namesOfClasses;
	std::vector<Class> classes;

public:
	// Student(std::string_view name, int const &numberOfClasses);
	// Student(std::string_view name, int const &numberOfClasses, std::vector<std::string> const &namesOfClasses);
	// Student(std::string_view name, std::vector<std::string> const &namesOfClasses);
	Student(std::string_view name, bool const &hasNamesForClasses, bool const &hasGradesForClasses, std::vector<Class> const &classes);

	std::string getName() const;
	int getNumberOfClasses() const;
	std::string getNameOfClass(int const &classNumber) const;
	int getClassPeriod(std::string_view className) const;
	std::vector<std::string> getNamesOfClasses() const;
	bool getHasNamesForClasses() const;

	void setName(std::string_view name);
	// void setNumberOfClasses(int const& numberOfClasses);
	bool setNameOfClass(int const &classPeriod, std::string_view newName);
	bool setNameOfClass(std::string_view oldName, std::string_view newName);
	bool setNamesOfClasses(std::vector<std::string> const &newNamesOfClasses);

	bool addClass();
	bool addClass(int const &classPeriod); // Moves everything above classPeriod forward one
	bool addClass(std::string_view className);
	bool addClass(int const &classPeriod, std::string_view className);

	bool removeClass();
	bool removeClass(int const &classPeriod);
	bool removeClass(std::string_view className);
};

std::ostream &operator<<(std::ostream &stream, Student const &student);
