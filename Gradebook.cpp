//#include <iostream>
#include <thread>
//#include "Student.hpp"
#include <chrono>
//#include <vector>
#include "Add.hpp"
#include "MrRed.hpp"
//#include <string>
//These should include all the commented out includes

int main()
{
	bool runningProgram = true;
	std::vector<Student> students;
	while (runningProgram) {
		using namespace std::chrono_literals;
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
				bool invalidResponse;
				do {
					invalidResponse = false;
					if (students.empty())
						std::cout << "\nSorry, looks like no students have been added yet.\n\n";
					else {
						cOutAndWait("\nOk, let's check student info!\n", 1);
						std::cout << "Would you like to see all students or a specific one?\n:";
						std::getline(std::cin, choice);
						std::getline(std::cin, choice);
						if (stringEqualsOneOfTheFollowingIgnoreCase(choice, { "all students", "all" }))
						{
							for (Student student : students)
								std::cout << student;
							std::cout << std::endl << std::endl << std::endl;
						}
						else if (stringEqualsOneOfTheFollowingIgnoreCase(choice, { "specific", "one", "specific one" }))
						{
							std::cout << "\nWhich student would you like to lookup?\n:";
							std::getline(std::cin, choice);
							std::getline(std::cin, choice);
							bool needsToRedo;
							do {
								needsToRedo = false;
								std::vector<Student*> matchedStudents;
								unsigned int i = 0;
								for (Student student : students)
								{
									if (toLowerCase(student.getName()) == toLowerCase(choice))
										matchedStudents.push_back(&(students[i]));
									i++;
								}
								if (matchedStudents.empty())
								{
									std::cout << "\n\nSorry, no students were found with that name. Try again, or type \"cancel\"\n:";
									needsToRedo = true;
								}
								else if (matchedStudents.size() > 1)
								{
									std::cout << "\n\nMultiple students were found with that name.\n\n";
								}
								for (Student* student : matchedStudents)
									std::cout << *student;
								std::cout << std::endl << std::endl << std::endl;
							} while (needsToRedo);
						}
						else {
							std::cout << "\nPlease type \"specific\" or \"all\"\n\n";
							invalidResponse = true;
						}
					}
				}
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

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
