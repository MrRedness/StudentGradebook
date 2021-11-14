#include "Student.hpp"
#include "MrRed.hpp"

// Helper Functions
bool Student::outOfBounds(int const &input)
{
	return input <= 0 || input > classes.size();
}

// Constructors

Student::Student(std::string_view name, bool const &hasNamesForClasses, bool const &hasGradesForClasses, std::vector<Class> const &classes)
	: name(name), hasNamesForClasses(hasNamesForClasses), hasGradesForClasses(hasGradesForClasses), classes(classes){};

// GETTERS

std::string Student::getName() const
{
	return name;
}

int Student::getNumberOfClasses() const { return classes.size(); }

// std::string Student::getNameOfClass(int const &classNumber) const
// {
// 	if (classNumber > 0 && classNumber <= classes.size())
// 		return classes[classNumber - 1].name;
// 	else
// 		return "Invalid Class Number";
// }

int Student::getClassPeriod(std::string_view className) const
{
	for (unsigned int i = 0; i < classes.size(); i++)
	{
		if (stringEqualsIgnoreCase(classes[i].name, className))
			return i + 1;
	}
	return 0;
}

// std::vector<Class> &Student::getClasses() { return (classes); }
std::vector<Class> const &Student::getClasses() const { return classes; };

bool Student::getHasNamesForClasses() const { return hasNamesForClasses; }
bool Student::getHasGradesForClasses() const { return hasGradesForClasses; }

// SETTERS

void Student::setName(std::string_view newName) { this->name = newName; }

bool Student::setNameOfClass(int const &classPeriod, std::string_view newName)
{
	if (outOfBounds(classPeriod))
		return false;
	classes[classPeriod - 1].name = newName;
	return true;
}

bool Student::setNameOfClass(std::string_view oldName, std::string_view newName)
{
	for (Class &clas : classes)
	{
		if (stringEqualsIgnoreCase(clas.name, oldName))
		{
			clas.name = newName;
			return true;
		}
	}
	return false;
}

bool Student::setGradeForClass(int const &classPeriod, int const &grade)
{
	if (outOfBounds(classPeriod) || grade > 100 || grade < 0)
		return false;
	classes[classPeriod - 1].grade = grade;
	return true;
}
bool Student::setGradeForClass(std::string_view className, int const &grade)
{
	for (Class &clas : classes)
	{
		if (stringEqualsIgnoreCase(clas.name, className))
		{
			clas.grade = grade;
			return true;
		}
	}
	return false;
}

// ADDERS

bool Student::addClass()
{
	if (classes.size() == classLimit)
		return false;
	classes.emplace_back(Class{"", -1});
	return true;
}

bool Student::addClass(int const &classPeriod)
{
	if (classes.size() == classLimit || classPeriod <= 0 || classPeriod > (classes.size() + 1))
		return false;
	classes.emplace(classes.begin() + (classPeriod - 1), Class{"", -1});
	return true;
}

bool Student::addClass(std::string_view className)
{
	if (classes.size() == classLimit)
		return false;
	classes.emplace(classes.end() + 1, Class{std::string(className), -1});
	return true;
}

bool Student::addClass(int const &classPeriod, std::string_view className)
{
	if (classes.size() == classLimit || classPeriod <= 0 || classPeriod > (classes.size() + 1))
		return false;
	classes.emplace(classes.begin() + (classPeriod - 1), Class{std::string(className), -1});
	return true;
}

// REMOVERS
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
	for (unsigned int i = 0; i < classes.size(); i++)
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
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	stream << "\nNumber of classes " << student.getName() << " is taking: " << student.getNumberOfClasses() << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(500));

	bool hasNames = student.getHasNamesForClasses();
	bool hasGrades = student.getHasGradesForClasses();

	auto const classes = student.getClasses();

	if (hasNames && hasGrades)
	{
		stream << "\nThe names & grades of those classes:" << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		int i = 1;
		for (Class const &clas : classes)
		{
			stream << "\n";
			if (clas.name == "")
				stream << i
					   << " (no name assigned)";
			else
				stream << clas.name;
			stream << " : ";
			if (clas.grade == -1)
				stream << "(no grade assigned)";
			else
				stream << clas.grade;
			i++;
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
		}
	}
	else if (hasNames)
	{
		stream << "\nThis student has no grades for their classes (yet)." << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		stream << "\nThe names of those classes: " << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		int i = 1;
		for (Class const &clas : classes)
		{
			stream << "\n";
			if (clas.name == "")
				stream << i
					   << " (no name assigned)";
			else
				stream << clas.name;
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
		}
	}
	else if (hasGrades)
	{
		stream << "\nThis student has no names for their classes (yet)." << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		stream << "\nThe grades of those classes: " << std::endl;
		int i = 1;
		for (Class const &clas : classes)
		{
			stream << "\n"
				   << i << " : ";
			if (clas.grade == -1)
				stream << "(no grade assigned)";
			else
				stream << clas.grade;
			i++;
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
		}
	}
	else
	{
		stream << "\nThis student has no names or grades for their classes (yet)." << std::endl;
	}
	return stream;
}
