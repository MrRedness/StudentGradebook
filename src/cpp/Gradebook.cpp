#include "Add.hpp"
#include "Check.hpp"
#include "Edit.hpp"
#include "MrRed.hpp"

// I understand and appreciate the aversion from "using namespace" but
// sometimes there are valid reasons, literals are one of those valid exceptions
// They tend to make code cleaner and easier to read, and I beleive are worth while.
// literals are typically the only exception I make to the rule of not "using namespace"
using namespace std::chrono_literals;

// int allocatedMem = 0;
// void *operator new(size_t size)
// {
//     std::cout << "Allocating " << size << "bytes\n";
//     allocatedMem += size;
//     std::cout << "Total allocated " << allocatedMem << " bytes\n";
//     return malloc(size);
// }
// void operator delete(void *memory, size_t size)
// {
//     std::cout << "Freeing " << size << "bytes\n";
//     allocatedMem -= size;
//     std::cout << "Total allocated " << allocatedMem << " bytes\n";
//     free(memory);
// }

int main()
{
    std::vector<Student> students;
    while (1)
    {
        cOutAndWait("Welcome to the Gradebook", .5s);
        cOutAndWait("Would you like to...", .5s);
        cOutAndWait("Add a Student? (type add)", .5s);
        cOutAndWait("Check Student Info? (type check)", .5s);
        cOutAndWait("Edit student name or (add/remove/edit) classes? (type edit)", .5s);
        cOutAndWait("Or input/change grades? (type input)", .5s);
        cOutAndWait("(Type \"exit\" to quit)", .5s);
        std::cout << ":";
        bool reenteringChoice;
        do
        {
            std::string choice;
            std::cin >> choice;
            reenteringChoice = false;
            if (stringEqualsOneOfTheFollowingIgnoreCase(choice, "add", "a"))
            {
                cOutAndWait("\nOk, let's add a student!\n", .5s);
                students.emplace_back(Add::addStudent());
                std::cout << students.back() << "\n\n\n";
            }
            else if (stringEqualsOneOfTheFollowingIgnoreCase(choice, "check", "c"))
            {
                Check::getStudentInfoFrom(students);
            }
            else if (stringEqualsOneOfTheFollowingIgnoreCase(choice, "edit", "e"))
            {
                Edit::editStudents(students);
                std::this_thread::sleep_for(1s);
            }
            else if (stringEqualsOneOfTheFollowingIgnoreCase(choice, "input", "i"))
            {
                cOutAndWait("Ok, time to input grades!\n", .5s);
            }
            else if (stringEqualsOneOfTheFollowingIgnoreCase(choice, "stop", "exit", "cancel"))
            {
                std::cout << "\n\nExiting";
                return 0;
            }
            else
            {
                cOutAndWait("\nI'm sorry. It seems you entered an invalid choice. Please use \"add\", \"check\", \"edit\", or \"input\".\n", .5s);
                std::cout << ":";
                reenteringChoice = true;
            }
        } while (reenteringChoice);
    }
}
