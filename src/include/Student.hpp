#pragma once
#include "PCH.hpp"

struct Class
{
	std::string name;
	int grade;
};

class Student
{
private:
	std::string name;
	bool hasNamesForClasses;
	bool hasGradesForClasses;
	std::vector<Class> classes;
	bool outOfBounds(int const &input);

public:
	static int const classLimit = 10;

	Student(std::string_view name, bool const &hasNamesForClasses, bool const &hasGradesForClasses, std::vector<Class> const &classes);

	std::string getName() const;
	int getNumberOfClasses() const;
	std::string getNameOfClass(int const &classNumber) const;
	int getClassPeriod(std::string_view className) const;
	// std::vector<Class> &getClasses();
	std::vector<Class> const &getClasses() const;

	bool getHasNamesForClasses() const;
	bool getHasGradesForClasses() const;

	void setName(std::string_view name);
	bool setNameOfClass(int const &classPeriod, std::string_view newName);
	bool setNameOfClass(std::string_view oldName, std::string_view newName);
	bool setGradeForClass(int const &classPeriod, int const &grade);
	bool setGradeForClass(std::string_view className, int const &grade);

	bool addClass();
	bool addClass(int const &classPeriod); // Moves everything above classPeriod forward one
	bool addClass(std::string_view className);
	bool addClass(int const &classPeriod, std::string_view className);

	bool removeClass();
	bool removeClass(int const &classPeriod);
	bool removeClass(std::string_view className);
};

std::ostream &operator<<(std::ostream &stream, Student const &student);
