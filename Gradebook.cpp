// Gradebook.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
//#include <chrono>

int main()
{
    using namespace std::chrono_literals;
    std::cout << "Welcome to the Gradebook \n";
    std::this_thread::sleep_for(1s);
    std::cout << "Would you like to... \n";
    std::this_thread::sleep_for(1s);
    std::cout << "Add a Student? (type add) \n";
    std::this_thread::sleep_for(1s);
    std::cout << "Check Student Info? (type check) \n";
    std::this_thread::sleep_for(1s);
    std::cout << "Or input grades? (type input) \n";

    bool runningProgram = true;
    while (runningProgram) {
        std::string choice;
        std::cin >> choice;
        if (choice._Equal("add") || choice._Equal("Add") || choice._Equal("a"))
        {
            std::cout << "Ok, let's add a student!\n";
        }
        else if (choice._Equal("check") || choice._Equal("Check") || choice._Equal("c"))
        {
            std::cout << "Ok, let's check a student's info!\n";
        }
        else if (choice._Equal("input") || choice._Equal("Input") || choice._Equal("i"))
        {
            std::cout << "Ok, time to input grades!\n";
        }
        else {
            std::cout << "I'm sorry. It seems you entered an invalid choice. Please use \"add\", \"check\", or \"input\".\n";
        }
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
