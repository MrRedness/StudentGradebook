//#include <iostream>
//#include <thread>
//#include "Student.hpp"
//#include <chrono>
//#include <vector>
#include "Add.hpp"
#include "MrRed.hpp"
#include "Check.hpp"

int main()
{
	bool runningProgram = true;
	std::vector<Student> students;
	while (runningProgram) {
		cOutAndWait("Welcome to the Gradebook", 1);
		cOutAndWait("Would you like to...", 1);
		cOutAndWait("Add a Student? (type add)", 1);
		cOutAndWait("Check Student Info? (type check)", 1);
		cOutAndWait("Or input grades? (type input)", 1);
		std::cout << ":";
		bool reenteringChoice;
		do {
			std::string choice;
			std::cin >> choice;
			reenteringChoice = false;
			if (stringEqualsOneOfTheFollowingIgnoreCase(choice, { "add", "a" }))
			{
				cOutAndWait("\nOk, let's add a student!\n", 1);
				students.emplace_back(Add::addStudent());
				std::cout << students.back() << "\n\n\n";
			}
			else if (stringEqualsOneOfTheFollowingIgnoreCase(choice, { "check", "c" }))
			{
				Check::getStudentInfoFrom(students);
			}
			else if (stringEqualsOneOfTheFollowingIgnoreCase(choice, { "input", "i" }))
			{
				cOutAndWait("Ok, time to input grades!\n", 1);
			}
			else {
				cOutAndWait("\nI'm sorry. It seems you entered an invalid choice. Please use \"add\", \"check\", or \"input\".\n", 1);
				std::cout << ":";
				reenteringChoice = true;
			}
		} while (reenteringChoice);
	}
}
