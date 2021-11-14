#include "Add.hpp"
#include "MrRed.hpp"
#include "Check.hpp"
#include "Edit.hpp"

void *operator new(size_t size)
{
	std::cout << "Allocating " << size << "bytes\n";
	return malloc(size);
}

int main()
{
	std::thread mainThread = std::thread([&]()
										 {
											 std::thread listenForStop = std::thread([&mainThread]()
																					 {
																						 while (1)
																						 {
																							 std::string input;
																							 std::cin >> input;
																							 if (stringEqualsOneOfTheFollowingIgnoreCase(input, {"stop", "exit", "cancel"}))
																							 {
																								 std::cout << "\n\nExiting";
																								 mainThread.join();
																							 }
																							 std::this_thread::sleep_for(std::chrono::milliseconds(100));
																						 }
																					 });
											 std::vector<Student> students;
											 cOutAndWait("Welcome to the Gradebook", 1);
											 cOutAndWait("Would you like to...", 1);
											 cOutAndWait("Add a Student? (type add)", 1);
											 cOutAndWait("Check Student Info? (type check)", 1);
											 cOutAndWait("Edit student name or (add/remove/edit) classes? (type edit)", 1);
											 cOutAndWait("Or input/change grades? (type input)", 1);
											 std::cout << ":";
											 bool reenteringChoice;
											 do
											 {
												 std::string choice;
												 std::cin >> choice;
												 reenteringChoice = false;
												 if (stringEqualsOneOfTheFollowingIgnoreCase(choice, {"add", "a"}))
												 {
													 cOutAndWait("\nOk, let's add a student!\n", 1);
													 students.emplace_back(Add::addStudent());
													 std::cout << students.back() << "\n\n\n";
												 }
												 else if (stringEqualsOneOfTheFollowingIgnoreCase(choice, {"check", "c"}))
												 {
													 Check::getStudentInfoFrom(students);
												 }
												 else if (stringEqualsOneOfTheFollowingIgnoreCase(choice, {"edit", "e"}))
												 {
													 Edit::editStudents(students);
												 }
												 else if (stringEqualsOneOfTheFollowingIgnoreCase(choice, {"input", "i"}))
												 {
													 cOutAndWait("Ok, time to input grades!\n", 1);
												 }
												 else
												 {
													 cOutAndWait("\nI'm sorry. It seems you entered an invalid choice. Please use \"add\", \"check\", or \"input\".\n", 1);
													 std::cout << ":";
													 reenteringChoice = true;
												 }
											 } while (reenteringChoice);
										 });
}
