#include "Edit.hpp"
#include "MrRed.hpp"

using namespace std::chrono_literals;

void Edit::editStudents(std::vector<Student> &students)
{
    if (students.empty())
    {
        std::cout << "\nSorry, looks like no students have been added yet.\n\n";
        return;
    }
    cOutAndWait("\nList of students", 1s);
    unsigned int i = 1;
    for (Student &stu : students)
    {
        std::cout << i << " : " << stu.getName() << std::endl;
        std::this_thread::sleep_for(500ms);
        i++;
    }
    std::cout << "\nWhich student would you like to edit? Enter the number here\n:";
    editStudent(students[cinInt(1, students.size()) - 1]);
}
void Edit::editStudent(Student &student)
{
    std::string name = student.getName();
    std::string input;
    cOutAndWait("\nEditing Student", 1s);
    std::cout << student;
    std::cout << "\n\n\nWhat would you like to edit? " << name << "'s name or classes?\n:";
    while (1)
    {

        std::cin >> input;
        if (stringEqualsOneOfTheFollowingIgnoreCase(input, "name"))
        {
            {
                std::cout << "\n\nWhat would you like the student's new name to be?";
                std::getline(std::cin, input);
                std::cout << "\n\nAre you sure you wish to change the name of " << name << " to " << input << ".\n:";
                std::string areYouSure;
                std::cin >> areYouSure;
                while (1)
                {
                    if (stringEqualsOneOfTheFollowingIgnoreCase(areYouSure, "yes", "ye", "sure", "y"))
                    {
                        student.setName(input);
                        std::cout << "\n\nOk, name changed!";
                        return;
                    }
                    else if (!stringEqualsOneOfTheFollowingIgnoreCase(areYouSure, "no", "n", "cancel"))
                        std::cout << "\n\nPlease type either \"yes\" or \"no\"\n:";
                }
            }
        }
        else if (stringEqualsOneOfTheFollowingIgnoreCase(input, "classes"))
        {
            while (1)
            {
                std::cout << "]n\nWould you like to edit, add, move, or delete a class?\n:";
                std::cin >> input;
                if (stringEqualsOneOfTheFollowingIgnoreCase(input, "edit", "e"))
                {
                    std::cout << "\n\n" << name << "'s classes:\n";
                    int i = 0;
                    for (Class clas& : student.getClasses())
                    {
                        std::cout << ++i << " : " << clas.name << std::endl;
                    }
                    std::cout << "\n\nWhich class would you like to edit (type number)?\n:";
                    size_t clasPeriod = cinInt(size_t(1), student.getNumberOfClasses()) - 1;
                    Class clas = student.getClasses().at(clasPeriod);
                    std::cout << "\n\nOk, you selected class " << clasPeriod << ", name: " << clas.name << ".\n";
                    std::this_thread::sleep_for(500ms);
                    if (clas.grade != -1)
                        std::cout << name << " has a " << clas.grade << " in the class.";
                    else
                        std::cout << "The grade for this class has not yet been entered but can be handled using either the \"input\" feature of this app or right here with the \"edit\" feature.";
                    std::this_thread::sleep_for(500ms);
                    std::cout << "\n\nSo, would you like to edit the class' name or grade?\n:";
                    while (1)
                    {
                        std::cin >> input;
                        if (stringEqualsOneOfTheFollowingIgnoreCase(input, "name", "n"))
                        {
                            while (1)
                            {
                                std::cin >> input;
                                std::cout << "\n\nOk, what would you like the new name to be?\n:";
                                std::getline(std::cin, input);
                                std::cout << "\n\nAre you sure you wish to change the name of " << clas.name << " to " << input << ".\n:";
                                std::string areYouSure;
                                std::cin >> areYouSure;
                                if (stringEqualsOneOfTheFollowingIgnoreCase(areYouSure, "yes", "ye", "sure", "y"))
                                {
                                    clas.name = input;
                                    std::cout << "\n\nOk, name changed!";
                                    return;
                                }
                                else if (!stringEqualsOneOfTheFollowingIgnoreCase(areYouSure, "no", "n", "cancel"))
                                    std::cout << "\n\nPlease type either \"yes\" or \"no\"\n:";
                            }
                        }
                        else if (stringEqualsOneOfTheFollowingIgnoreCase(input, "grade", "g"))
                        {
                            while (1)
                            {
                                std::cout << "\n\nOk, what would you like the new grade to be?\n:";
                                int newGrade = cinInt(0, 100);
                                std::cout << "\n\nAre you sure you wish to change the grade of " << clas.name << " to " << newGrade << ".\n:";
                                std::string areYouSure;
                                std::cin >> areYouSure;
                                if (stringEqualsOneOfTheFollowingIgnoreCase(areYouSure, "yes", "ye", "sure", "y"))
                                {
                                    clas.grade = newGrade;
                                    std::cout << "\n\nOk, grade changed!";
                                    return;
                                }
                                else if (!stringEqualsOneOfTheFollowingIgnoreCase(areYouSure, "no", "n", "cancel"))
                                    std::cout << "\n\nPlease type either \"yes\" or \"no\"\n:";
                            }
                        }
                        else
                            std::cout << "\n\nPlease use either \"name\" or \"grade\"\n:";
                    }
                }
                // if add
                // if move
                // if delete
                else
                    std::cout << "\n\nPlease use \"edit\", \"add\", \"move\", or \"delete\"\n:";
            }
        }
        else
        {
            std::cout << "\n\nPlease use either \"name\" or \"class\"\n:";
        }
    }
}