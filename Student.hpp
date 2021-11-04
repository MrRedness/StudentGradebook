#pragma once
#include <iostream>
#include <vector>

class Student {
private:
	std::string name;
	int numberOfClasses;
	std::vector<std::string> namesOfClasses;
public:
	Student(const std::string& name, const int& numberOfClasses);
	Student(const std::string& name, const int& numberOfClasses, const std::vector<std::string>& namesOfClasses);
	Student(const std::string& name, const std::vector<std::string>& namesOfClasses);

	std::string getName() const;
	int getNumberOfClasses() const;
	std::string getNameOfClass(int classNumber) const;
	int getClassPeriod(std::string className) const;
	std::vector<std::string> getNamesOfClasses() const;

	void setName(const std::string& name);
	//void setNumberOfClasses(const int& numberOfClasses);
	bool setNameOfClass(const int& classPeriod, const std::string& newName);
	bool setNameOfClass(const std::string& oldName, const std::string& newName);
	bool setNamesOfClasses(const std::vector<std::string>& newNamesOfClasses);

	bool addClass();
	bool addClass(const int& classPeriod); // Moves everything above classPeriod forward one
	bool addClass(const std::string& className);
	bool addClass(const int& classPeriod, const std::string& className);

	bool removeClass();
	bool removeClass(const int& classPeriod);
	bool removeClass(const std::string& className);
};

std::ostream& operator<<(std::ostream& stream, const Student& student);
