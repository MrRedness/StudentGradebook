#include "Edit.hpp"
#include "MrRed.hpp"

using namespace std::chrono_literals;

static std::string input;

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
        std::cout << i << " : " << stu.getName() << "\n";
        std::this_thread::sleep_for(500ms);
        i++;
    }
    std::cout << "\nWhich student would you like to edit? Enter the number here\n:";
    editStudent(students[cinInt(1, students.size()) - 1]);
}
void Edit::editStudent(Student &student)
{
    std::string name = student.getName();
    cOutAndWait("\nEditing Student", 1s);
    std::cout << student;
    std::cout << "What would you like to edit? " << name << "'s name or classes?\n:";
    while (1)
    {

        std::cin >> input;
        if (stringEqualsOneOfTheFollowingIgnoreCase(input, "name", "n"))
        {
            editStudentName(student);
            return;
        }
        else if (stringEqualsOneOfTheFollowingIgnoreCase(input, "classes", "class", "c"))
        {
            editStudentClasses(student);
            return;
        }
        else
        {
            std::cout << "\n\nPlease use either \"name\" or \"classes\"\n:";
        }
    }
}

void Edit::editStudentName(Student &student)
{
    while (1)
    {
        std::cout << "\n\nWhat would you like the student's new name to be?\n:";
        std::getline(std::cin, input);
        std::getline(std::cin, input);
        std::cout << "\n\nAre you sure you wish to change the name of " << student.getName() << " to " << input << "?\n:";
        std::string areYouSure;
        std::cin >> areYouSure;
        if (stringEqualsOneOfTheFollowingIgnoreCase(areYouSure, "yes", "ye", "sure", "y"))
        {
            student.setName(input);
            std::cout << "\n\nOk, name changed!\n\n";
            return;
        }
        else if (!stringEqualsOneOfTheFollowingIgnoreCase(areYouSure, "no", "n", "cancel"))
            std::cout << "\n\nPlease type either \"yes\" or \"no\"\n:";
    }
}

void Edit::editStudentClasses(Student &student)
{
    while (1)
    {
        std::cout << "\n\nWould you like to edit, add, move, or delete a class?\n:";
        std::cin >> input;
        if (stringEqualsOneOfTheFollowingIgnoreCase(input, "edit", "e"))
        {
            editClass(getClass(student, "edit"));
            return;
        }
        else if (stringEqualsOneOfTheFollowingIgnoreCase(input, "add", "a"))
        {
            addClass(student);
            return;
        }
        else if (stringEqualsOneOfTheFollowingIgnoreCase(input, "move", "m"))
        {
            moveClass(getClass(student, "move"));
            return;
        }
        else if (stringEqualsOneOfTheFollowingIgnoreCase(input, "delete", "del", "remove", "trash", "rm", "d"))
        {
            deleteClass(getClass(student, "delete"));
        }
        else
            std::cout << "\n\nPlease use \"edit\", \"add\", \"move\", or \"delete\"\n:";
    }
}

Class &Edit::getClass(Student &student, std::string_view msg)
{
    std::cout << "\n\n"
              << student.getName() << "'s classes:\n";
    int i = 0;
    for (Class const &clas : student.getClasses())
    {
        std::cout << ++i << " : " << clas.name << "\n";
    }
    std::cout << "\n\nWhich class would you like to " << msg << " (type number)?\n:";
    size_t clasPeriod = cinInt(1, student.getNumberOfClasses());
    Class &clas = student.getClasses().at(clasPeriod - 1);
    std::cout << "\n\nOk, you selected class " << clasPeriod << ", name: " << clas.name << ".\n\n";
    std::this_thread::sleep_for(500ms);
    if (clas.grade != -1)
        std::cout << student.getName() << " has a " << clas.grade << " in the class.\n";
    else
        std::cout << "The grade for this class has not yet been entered but can be handled using either the \"input\" feature of this app or right here with the \"edit\" feature.\n\n";
    std::this_thread::sleep_for(500ms);
    return clas;
}

void Edit::editClass(Class &clas)
{

    std::cout << "\nWould you like to edit the class' name or grade?\n:";
    while (1)
    {
        std::cin >> input;
        if (stringEqualsOneOfTheFollowingIgnoreCase(input, "name", "n"))
        {
            while (1)
            {
                std::cout << "\n\nOk, what would you like the new name to be?\n:";
                std::getline(std::cin, input);
                std::getline(std::cin, input);
                std::cout << "\n\nAre you sure you wish to change the name of " << clas.name << " to " << input << "?\n:";
                std::string areYouSure;
                std::cin >> areYouSure;
                if (stringEqualsOneOfTheFollowingIgnoreCase(areYouSure, "yes", "ye", "sure", "y"))
                {
                    clas.name = input;
                    std::cout << "\n\nOk, name changed!\n\n";
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
                std::cout << "\n\nAre you sure you wish to change the grade of " << clas.name << " from " <<clas.grade << " to " << newGrade << "?\n:";
                std::string areYouSure;
                std::cin >> areYouSure;
                if (stringEqualsOneOfTheFollowingIgnoreCase(areYouSure, "yes", "ye", "sure", "y"))
                {
                    clas.grade = newGrade;
                    std::cout << "\n\nOk, grade changed!\n\n";
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

void Edit::addClass(Student &student)
{
}

void Edit::moveClass(Class &clas)
{
}
void Edit::deleteClass(Class &clas)
{
}