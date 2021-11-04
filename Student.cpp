#include "Student.hpp"
#include "MrRed.hpp"

Student::Student(const std::string& name, const int& numberOfClasses)
	: name(name), numberOfClasses(numberOfClasses)
{
	for (int i = 0; i < numberOfClasses; i++) {
		namesOfClasses.emplace_back("");
	}
};
Student::Student(const std::string& name, const int& numberOfClasses, const std::vector<std::string>& namesOfClasses)
	: name(name), numberOfClasses(numberOfClasses), namesOfClasses(namesOfClasses) {};
Student::Student(const std::string& name, const std::vector<std::string>& namesOfClasses)
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

void Student::setName(const std::string& name) { this->name = name; }

//void Student::setNumberOfClasses(const int& numberOfClasses) { 
//	this->numberOfClasses = numberOfClasses; 
//}

bool Student::setNameOfClass(const int& classPeriod, const std::string& newName)
{
	for (std::string nameOfClass : namesOfClasses)
	{
		if (stringEqualsIgnoreCase(nameOfClass, newName))
		{
			nameOfClass = newName;
			return true;
		}
	}
	return false;
}

bool Student::setNameOfClass(const std::string& oldName, const std::string& newName)
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

bool Student::setNamesOfClasses(const std::vector<std::string>& newNamesOfClasses)
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

bool Student::addClass(const int& classPeriod)
{
	if (numberOfClasses == 10 || classPeriod <= 0 || classPeriod > (numberOfClasses + 1))
		return false;
	numberOfClasses++;
	namesOfClasses.emplace(namesOfClasses.begin() + (classPeriod - 1), "");
	return true;
}

bool Student::addClass(const std::string& className)
{
	if (numberOfClasses == 10)
		return false;
	numberOfClasses++;
	namesOfClasses.emplace_back(className);
	return true;
}

bool Student::addClass(const int& classPeriod, const std::string& className)
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

bool Student::removeClass(const int& classPeriod)
{
	if (numberOfClasses == 1 || classPeriod <= 0 || classPeriod > numberOfClasses)
		return false;
	numberOfClasses--;
	namesOfClasses.erase(namesOfClasses.begin() + (classPeriod - 1));
	return true;
}

bool Student::removeClass(const std::string& className)
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

std::ostream& operator<<(std::ostream& stream, const Student& student)
{
	stream << "\n\nStudent Name: " << student.getName() << std::endl
		<< "\nNumber of Classes " << student.getName() << " is taking: " << student.getNumberOfClasses() << std::endl
		<< "\nThe names of those Classes: " << std::endl;
	for (std::string nameOfClass : student.getNamesOfClasses())
	{
		stream << "\n" << nameOfClass;
	}
	return stream;
}









