#include "Check.hpp"
#include "MrRed.hpp"

using namespace std::chrono_literals;

void Check::getStudentInfoFrom(std::vector<Student> const &students)
{
    std::string choice;
    if (students.empty())
    {
        std::cout << "\nSorry, looks like no students have been added yet.\n\n";
        return;
    }
    bool invalidResponse;
    cOutAndWait("\nOk, let's check student info!\n", 1s);
    std::getline(std::cin, choice);
    do
    {
        invalidResponse = false;
        std::cout << "Would you like to see all students or a specific one?\n:";
        std::getline(std::cin, choice);
        if (stringEqualsOneOfTheFollowingIgnoreCase(choice, "all students", "all"))
        {
            printAllStudentInfo(students);
            return;
        }
        else if (stringEqualsOneOfTheFollowingIgnoreCase(choice, "specific", "one", "specific one"))
        {
            getSpecificStudentInfo(students);
            return;
        }
        else
        {
            std::cout << "\nPlease type \"specific\" or \"all\"\n\n";
            invalidResponse = true;
        }
    } while (invalidResponse);
}

void Check::printAllStudentInfo(std::vector<Student> const &students)
{
    for (Student const &student : students)
        std::cout << student;
    std::cout << "\n\n\n";
}

void Check::getSpecificStudentInfo(std::vector<Student> const &students)
{
    std::string input;
    std::cout << "\nWhich student would you like to lookup?\n:";
    std::getline(std::cin, input);
    bool needsToRedo;
    do
    {
        std::string inputLC = toLowerCase(input);
        needsToRedo = false;
        std::vector<Student const*> matchedStudents;
        unsigned int i = 0;
        for (Student const &student : students)
        {
            std::string studentNameLC = toLowerCase(student.getName());
            if (studentNameLC == inputLC || studentNameLC.substr(0, studentNameLC.find_first_of(" ")) == inputLC ||  studentNameLC.substr(studentNameLC.find_last_of(" ") + 1) == inputLC)
                matchedStudents.push_back(&students[i]);
            i++;
        }
        if (matchedStudents.empty())
        {
            std::cout << "\n\nSorry, no students were found with that name. Try again, or type \"cancel\"\n:";
            std::getline(std::cin, input);
            if (toLowerCase(input) != "cancel")
                needsToRedo = true;
        }
        else if (matchedStudents.size() > 1)
        {
            cOutAndWait("\n\nMultiple students were found with that name.\n\n", 1s);
        }
        for (Student const* student : matchedStudents)
            std::cout << "\n\n" << *student;
        std::cout << "\n\n\n";
    } while (needsToRedo);
}