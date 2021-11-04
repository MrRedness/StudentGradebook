// #include <iostream>
// #include <thread>
// #include "Student.hpp"
//#include <chrono>
//#include <vector>

#include "Add.hpp"
#include "MrRed.hpp"
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
            if (stringEqualsIgnoreCase(choice, "add", "a"))
            {
                cOutAndWait("\nOk, let's add a student!\n", 1);
                students.emplace_back(Add::addStudent());
                std::cout << students.back() << "\n\n";
            }
            else if (stringEqualsIgnoreCase(choice, "check", "c"))
            {
                cOutAndWait("Ok, let's check a student's info!\n", 1);
                for (Student student : students)
                    std::cout << student;
            }
            else if (stringEqualsIgnoreCase(choice, "input", "i"))
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
