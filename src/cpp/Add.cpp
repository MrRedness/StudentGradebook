#include "Add.hpp"
#include "MrRed.hpp"

Student Add::addStudent()
{
    using namespace std::chrono_literals;

    std::string name;
    std::size_t numberOfClasses;
    std::string nameClassesString;
    bool nameClassesBool;
    std::string gradeClassesString;

    std::cout << "What is the student's name?\n:";
    std::getline(std::cin, name); // why twice?
    std::getline(std::cin, name);
    std::cout << "\n\nOk, how many classes is " + name + " taking?\n:";
    numberOfClasses = cinInt(1, Student::classLimit);
    std::vector<Class> classes;
    classes.reserve(numberOfClasses); // pre allocate enough memory for the classes
    for (std::size_t i = 0; i < numberOfClasses; i++)
        classes.emplace_back("", -1); // you lose the benifits of emplace if you construct it here
    bool invalidAnswer;               // = true; // why initiaze to true if youre going to immediatly set it to false?
    do
    {
        invalidAnswer = false;
        std::cout << "\n\nWould you like to give each class a name? (type yes/no)\n:";
        std::cin >> nameClassesString;
        if (stringEqualsOneOfTheFollowingIgnoreCase(nameClassesString, "yes", "ye", "sure", "y"))
        {
            nameClassesBool = true;
            std::cout << "\nPlease enter the name for each class or leave it blank\n";
            std::string input;
            std::getline(std::cin, input);
            for (std::size_t i = 0; i < numberOfClasses; i++)
            {
                std::cout << "\nClass " << i + 1 << "\n:";
                std::getline(std::cin, input);
                classes[i].name = input;
            }
            // for (unsigned int i = 0; i < numberOfClasses; i++)
            //{
            //	std::cout << "\n" << namesOfClasses[i];
            // }
        }
        else if (stringEqualsOneOfTheFollowingIgnoreCase(nameClassesString, "no", "n"))
        {
            nameClassesBool = false;
        }
        else
        {
            std::cout << "\nPlease type either \"yes\" or \"no\".";
            invalidAnswer = true;
        }
    } while (invalidAnswer);
    while (1)
    {
        std::cout << "\n\nWould you like to enter grades for " + name + "'s classes? (type yes/no)\n:";
        std::cin >> gradeClassesString;
        if (stringEqualsOneOfTheFollowingIgnoreCase(gradeClassesString, "yes", "ye", "sure", "y"))
        {
            std::cout << "\nPlease enter the grade for each class (between 0 and 100) or type -1 for no grade.\n";
            std::string stringInput;
            std::getline(std::cin, stringInput);
            for (std::size_t i = 0; i < numberOfClasses; i++)
            {
                int gradeInput;
                std::cout << "\nClass " << i + 1 << "\n:";
                gradeInput = cinInt(-1, 100);
                classes[i].grade = gradeInput;
            }
            // for (unsigned int i = 0; i < numberOfClasses; i++)
            //{
            //	std::cout << "\n" << namesOfClasses[i];
            // }
            std::cout << "\n\nStudent " << name << " successfully added!\n\n";
            return Student(name, nameClassesBool, true, classes);
        }
        else if (stringEqualsOneOfTheFollowingIgnoreCase(gradeClassesString, "no", "n"))
        {
            std::cout << "\n\nStudent " << name << " successfully added!\n\n";
            return Student(name, nameClassesBool, false, classes);
        }
        else
        {
            std::cout << "\nPlease type either \"yes\" or \"no\".";
        }
    }
    // return Student(name, false, false, classes);
}