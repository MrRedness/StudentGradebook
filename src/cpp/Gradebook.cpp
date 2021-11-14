#include "Add.hpp"
#include "Check.hpp"
#include "Edit.hpp"
#include "MrRed.hpp"

// I understand and appreciate the aversion from "using namespace" but
// sometimes there are valid reasons, literals are one of those valid exceptions
// They tend to make code cleaner and easier to read, and I beleive are worth while.
// literals are typically the only exception I make to the rule of not "using namespace"
using namespace std::chrono_literals;

void *operator new(size_t size)
{
    std::cout << "Allocating " << size << "bytes\n";
    return malloc(size);
}

int main()
{
    std::thread mainThread { [&]() { // but there already was a main thread... (the one creating this one)
        // std::thread listenForStop { []() {       // polling user input on both threads is asking for a bad time
        //     while(1)
        //     {
        //         std::string input;
        //         std::cin >> input;
        //         if(stringEqualsOneOfTheFollowingIgnoreCase(input, { "stop", "exit", "cancel" }))
        //         {
        //             std::cout << "\n\nExiting";
        //             mainThread.join(); // this doesn't do what you think it does
        //                                // It makes this thread wait until the mainThread exits
        //                                // and doesn't do any thing to cause mainThread to exit
        //         }
        //         std::this_thread::sleep_for(100ms); // isn't that easier to read?
        //     }
        // } };
        std::vector<Student> students;
        cOutAndWait("Welcome to the Gradebook", 1s);
        cOutAndWait("Would you like to...", 1s);
        cOutAndWait("Add a Student? (type add)", 1s);
        cOutAndWait("Check Student Info? (type check)", 1s);
        cOutAndWait("Edit student name or (add/remove/edit) classes? (type edit)", 1s);
        cOutAndWait("Or input/change grades? (type input)", 1s);
        std::cout << ":";
        bool reenteringChoice;
        do
        {
            std::string choice;
            std::cin >> choice;
            reenteringChoice = false;
            if(stringEqualsOneOfTheFollowingIgnoreCase(choice, { "add", "a" }))
            {
                cOutAndWait("\nOk, let's add a student!\n", 1s);
                students.emplace_back(Add::addStudent());
                std::cout << students.back() << "\n\n\n";
            }
            else if(stringEqualsOneOfTheFollowingIgnoreCase(choice, { "check", "c" }))
            {
                Check::getStudentInfoFrom(students);
            }
            else if(stringEqualsOneOfTheFollowingIgnoreCase(choice, { "edit", "e" }))
            {
                Edit::editStudents(students);
            }
            else if(stringEqualsOneOfTheFollowingIgnoreCase(choice, { "input", "i" }))
            {
                cOutAndWait("Ok, time to input grades!\n", 1s);
            }
            else if(stringEqualsOneOfTheFollowingIgnoreCase(choice, { "stop", "exit", "cancel" }))
            {
                std::cout << "\n\nExiting";
                return;
            }
            else
            {
                cOutAndWait("\nI'm sorry. It seems you entered an invalid choice. Please use \"add\", \"check\", or \"input\".\n", 1s);
                std::cout << ":";
                reenteringChoice = true;
            }
        } while(reenteringChoice);
    } };
    mainThread.join(); // wait for mainThread to exit
    return 0;
}
