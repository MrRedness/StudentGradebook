#pragma once
#include <iostream>
#include <vector>
//#include <string_view>

class Student {
private:
	std::string name;
	int numberOfClasses;
	std::vector<std::string> namesOfClasses;
public:
	Student(std::string_view name, int const& numberOfClasses);
	Student(std::string_view name, int const& numberOfClasses, std::vector<std::string> const& namesOfClasses);
	Student(std::string_view name, std::vector<std::string> const& namesOfClasses);

	std::string getName() const;
	int getNumberOfClasses() const;
	std::string getNameOfClass(int classNumber) const;
	int getClassPeriod(std::string className) const;
	std::vector<std::string> getNamesOfClasses() const;

	void setName(std::string_view name);
	//void setNumberOfClasses(int const& numberOfClasses);
	bool setNameOfClass(int const& classPeriod, std::string_view newName);
	bool setNameOfClass(std::string_view oldName, std::string_view newName);
	bool setNamesOfClasses(std::vector<std::string> const& newNamesOfClasses);

	bool addClass();
	bool addClass(int const& classPeriod); // Moves everything above classPeriod forward one
	bool addClass(std::string_view className);
	bool addClass(int const& classPeriod, std::string_view className);

	bool removeClass();
	bool removeClass(int const& classPeriod);
	bool removeClass(std::string_view className);
};

std::ostream& operator<<(std::ostream& stream, Student const& student);
