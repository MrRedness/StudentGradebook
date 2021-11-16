#include "Edit.hpp"
#include "MrRed.hpp"

using namespace std::chrono_literals;

void Edit::editStudents(std::vector<Student> &students)
{
    cOutAndWait("List of students", 1s);
    unsigned int i = 1;
    for (Student &stu : students)
    {
        std::cout << i << " : " << stu.getName() << std::endl;
        std::this_thread::sleep_for(500ms);
        i++;
    }
    std::cout << "Which student would you like to edit? Enter the number here\n:";
    editStudent(students[cinInt(size_t(1), students.size())]);
}
void Edit::editStudent(Student &student)
{
    std::string name = student.getName();
    std::string input;
    while (1)
    {
        cOutAndWait("Editing Student", 1s);
        std::cout << student;
        std::cout << "What would you like to edit? " << name << "'s name or classes.\n:";
        std::cin >> input;
        if (stringEqualsOneOfTheFollowingIgnoreCase(input, {"name"}))
        {
            {
                std::cout << "What would you like the student's new name to be?";
                std::getline(std::cin, input);
                std::cout << "Are you sure you wish to change the name of " << name << " to " << input << ".\n:";
                std::string areYouSure;
                std::cin >> areYouSure;
                while (1)
                {
                    if (stringEqualsOneOfTheFollowingIgnoreCase(areYouSure, {"yes", "sure", "y"}))
                    {
                        student.setName(input);
                        std::cout << "\nOk, name changed!";
                        return;
                    }
                    else if (!stringEqualsOneOfTheFollowingIgnoreCase(areYouSure, {"no", "n", "cancel"}))
                        std::cout << "Please type either \"yes\" or \"no\"\n:";
                }
            }
        }
        else if (stringEqualsOneOfTheFollowingIgnoreCase(input, {"class"}))
        {
            while (1)
            {
                std::cout << "Would you like to edit, add, move, or delete a class?\n:";
                std::cin >> input;
                if (stringEqualsOneOfTheFollowingIgnoreCase(input, {"edit", "e"}))
                {
                    std::cout << "Which class would you like to edit (type number)?\n:";
                    size_t clasPeriod = cinInt(size_t(1), student.getNumberOfClasses());
                    Class clas = student.getClasses().at(clasPeriod);
                    std::cout << "Ok, you selected class " << clasPeriod << ", name: " << clas.name << ".\n";
                    std::this_thread::sleep_for(500ms);
                    if (clas.grade != -1)
                        std::cout << name << " has a " << clas.grade << " in the class.";
                    else
                        std::cout << "The grade for this class has not yet been entered but can be handled using either the \"input\" feature of this app or right here with the \"edit\" feature.";
                    std::this_thread::sleep_for(500ms);
                    std::cout << "So, would you like to edit the class' name or grade?\n:";
                    if (stringEqualsOneOfTheFollowingIgnoreCase(input, {"name", "n"}))
                    {
                        while (1)
                        {
                            std::cin >> input;
                            std::cout << "\nOk, what would you like the new name to be?\n:";
                            std::getline(std::cin, input);
                            std::cout << "Are you sure you wish to change the name of " << clas.name << " to " << input << ".\n:";
                            std::string areYouSure;
                            std::cin >> areYouSure;
                            if (stringEqualsOneOfTheFollowingIgnoreCase(areYouSure, {"yes", "sure", "y"}))
                            {
                                clas.name = input;
                                std::cout << "\nOk, name changed!";
                                return;
                            }
                            else if (!stringEqualsOneOfTheFollowingIgnoreCase(areYouSure, {"no", "n", "cancel"}))
                                std::cout << "Please type either \"yes\" or \"no\"\n:";
                        }
                    }
                    else if (stringEqualsOneOfTheFollowingIgnoreCase(input, {"grade", "g"}))
                    {
                        while (1)
                        {
                            std::cout << "\nOk, what would you like the new grade to be?\n:";
                            int newGrade = cinInt(0, 100);
                            std::cout << "Are you sure you wish to change the grade of " << clas.name << " to " << newGrade << ".\n:";
                            std::string areYouSure;
                            std::cin >> areYouSure;
                            if (stringEqualsOneOfTheFollowingIgnoreCase(areYouSure, {"yes", "sure", "y"}))
                            {
                                clas.grade = newGrade;
                                std::cout << "\nOk, grade changed!";
                                return;
                            }
                            else if (!stringEqualsOneOfTheFollowingIgnoreCase(areYouSure, {"no", "n", "cancel"}))
                                std::cout << "Please type either \"yes\" or \"no\"\n:";
                        }
                    }
                    else
                    {
                        std::cout << "Please use either \"name\" or \"class\"\n:";
                    }
                }
            }
        }
    }
}