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
	Student(std::string_view name, const int& numberOfClasses);
	Student(std::string_view name, const int& numberOfClasses, const std::vector<std::string>& namesOfClasses);
	Student(std::string_view name, const std::vector<std::string>& namesOfClasses);

	std::string getName() const;
	int getNumberOfClasses() const;
	std::string getNameOfClass(int classNumber) const;
	int getClassPeriod(std::string className) const;
	std::vector<std::string> getNamesOfClasses() const;

	void setName(std::string_view name);
	//void setNumberOfClasses(const int& numberOfClasses);
	bool setNameOfClass(const int& classPeriod, std::string_view newName);
	bool setNameOfClass(std::string_view oldName, std::string_view newName);
	bool setNamesOfClasses(const std::vector<std::string>& newNamesOfClasses);

	bool addClass();
	bool addClass(const int& classPeriod); // Moves everything above classPeriod forward one
	bool addClass(std::string_view className);
	bool addClass(const int& classPeriod, std::string_view className);

	bool removeClass();
	bool removeClass(const int& classPeriod);
	bool removeClass(std::string_view className);
};

std::ostream& operator<<(std::ostream& stream, const Student& student);
