#include "Check.hpp"
#include "MrRed.hpp"
#include <string>


void Check::getStudentInfoFrom(std::vector<Student> const& students)
{
bool invalidResponse;
std::string choice;
if (students.empty())
	std::cout << "\nSorry, looks like no students have been added yet.\n\n";
else {
	cOutAndWait("\nOk, let's check student info!\n", 1);
	std::getline(std::cin, choice);
	do {
		invalidResponse = false;
		std::cout << "Would you like to see all students or a specific one?\n:";
		std::getline(std::cin, choice);
		if (stringEqualsOneOfTheFollowingIgnoreCase(choice, { "all students", "all" }))
		{
			printAllStudentInfo(students);
		}
		else if (stringEqualsOneOfTheFollowingIgnoreCase(choice, { "specific", "one", "specific one" }))
		{
			getSpecificStudentInfo(students);
		}
		else {
			std::cout << "\nPlease type \"specific\" or \"all\"\n\n";
			invalidResponse = true;
		}
	} while (invalidResponse);
}
}

void Check::printAllStudentInfo(std::vector<Student> const& students) {
	for (Student const& student : students)
		std::cout << student;
	std::cout << std::endl << std::endl << std::endl;
}

void Check::getSpecificStudentInfo(std::vector<Student> const& students)
{
	std::string choice;
	std::cout << "\nWhich student would you like to lookup?\n:";
	std::getline(std::cin, choice);
	bool needsToRedo;
	do {
		needsToRedo = false;
		std::vector<const Student*> matchedStudents;
		unsigned int i = 0;
		for (Student const& student : students)
		{
			if (toLowerCase(student.getName()) == toLowerCase(choice))
				matchedStudents.push_back(&students[i]);
			i++;
		}
		if (matchedStudents.empty())
		{
			std::cout << "\n\nSorry, no students were found with that name. Try again, or type \"cancel\"\n:";
			std::getline(std::cin, choice);
			if (toLowerCase(choice) != "cancel")
				needsToRedo = true;
		}
		else if (matchedStudents.size() > 1)
		{
			cOutAndWait("\n\nMultiple students were found with that name.\n\n", 1);
		}
		for (const Student* student : matchedStudents)
			std::cout << *student;
		std::cout << std::endl << std::endl << std::endl;
	} while (needsToRedo);
}