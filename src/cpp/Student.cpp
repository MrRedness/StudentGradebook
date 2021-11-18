#include "Student.hpp"
#include "MrRed.hpp"

using namespace std::chrono_literals;

// Helper Functions
bool Student::outOfBounds(std::size_t input)
{
    return input <= 0 || input > classes.size();
}

// Constructors

Student::Student(std::string_view name, bool hasNamesForClasses, bool hasGradesForClasses, std::vector<Class> const &classes) // for literals, it can be faster to pass by value
    : name{name}                                                                                                              // prefer braced initializers always*, it helps distincify initialization from function calls
      ,
      hasNamesForClasses{hasNamesForClasses}, hasGradesForClasses{hasGradesForClasses}, classes{classes}
{
}

// GETTERS

std::string Student::getName() const
{
    return name;
}

std::size_t Student::getNumberOfClasses() const { return classes.size(); }

// std::string Student::getNameOfClass(int classNumber) const
// {
// 	if (classNumber > 0 && classNumber <= classes.size())
// 		return classes[classNumber - 1].name;
// 	else
// 		return "Invalid Class Number";
// }

std::size_t Student::getClassPeriod(std::string_view className) const
{
    for (unsigned int i = 0; i < classes.size(); i++)
    {
        if (stringEqualsIgnoreCase(classes[i].name, className))
            return i + 1;
    }
    return 0;
}

std::vector<Class> &Student::getClasses() { return classes; }
std::vector<Class> const &Student::getClasses() const { return classes; }

bool Student::getHasNamesForClasses() const { return hasNamesForClasses; }
bool Student::getHasGradesForClasses() const { return hasGradesForClasses; }

// SETTERS

void Student::setName(std::string_view newName) { this->name = newName; }

bool Student::setNameOfClass(std::size_t classPeriod, std::string_view newName)
{
    if (outOfBounds(classPeriod))
        return false;
    classes[classPeriod - 1].name = newName;
    return true;
}

bool Student::setNameOfClass(std::string_view oldName, std::string_view newName)
{
    for (Class &clas : classes)
    {
        if (stringEqualsIgnoreCase(clas.name, oldName))
        {
            clas.name = newName;
            return true;
        }
    }
    return false;
}

bool Student::setGradeForClass(std::size_t classPeriod, int grade)
{
    if (outOfBounds(classPeriod) || grade > 100 || grade < 0)
        return false;
    classes[classPeriod - 1].grade = grade;
    return true;
}
bool Student::setGradeForClass(std::string_view className, int grade)
{
    for (Class &clas : classes)
    {
        if (stringEqualsIgnoreCase(clas.name, className))
        {
            clas.grade = grade;
            return true;
        }
    }
    return false;
}

// ADDERS

bool Student::addClass()
{
    if (classes.size() == classLimit)
        return false;
    classes.emplace_back(Class{"", -1});
    return true;
}

bool Student::addClass(std::size_t classPeriod)
{
    if (classes.size() == classLimit || classPeriod <= 0 || classPeriod > (classes.size() + 1))
        return false;
    classes.emplace(classes.begin() + (classPeriod - 1), Class{"", -1});
    return true;
}

bool Student::addClass(std::string_view className)
{
    if (classes.size() == classLimit)
        return false;
    classes.emplace(classes.end() + 1, Class{std::string(className), -1});
    return true;
}

bool Student::addClass(std::size_t classPeriod, std::string_view className)
{
    if (classes.size() == classLimit || classPeriod <= 0 || classPeriod > (classes.size() + 1))
        return false;
    classes.emplace(classes.begin() + (classPeriod - 1), Class{className, -1});
    return true;
}

// REMOVERS
bool Student::removeClass()
{
    if (classes.size() == 1)
        return false;
    classes.pop_back();
    return true;
}

bool Student::removeClass(std::size_t classPeriod)
{
    if (classes.size() == 1 || classPeriod <= 0 || classPeriod > classes.size())
        return false;
    classes.erase(classes.begin() + (classPeriod - 1));
    return true;
}

bool Student::removeClass(std::string_view className)
{
    if (classes.size() == 1)
        return false;
    for (unsigned int i = 0; i < classes.size(); i++)
    {
        if (stringEqualsIgnoreCase(classes[i].name, className))
        {
            classes.erase(classes.begin() + i);
            return true;
        }
    }
    return false;
}

std::ostream &operator<<(std::ostream &stream, Student const &student)
{
    stream << "\n\nStudent Name: " << student.getName() << "\n";
    std::this_thread::sleep_for(500ms);
    stream << "\nNumber of classes " << student.getName() << " is taking: " << student.getNumberOfClasses() << "\n";
    std::this_thread::sleep_for(500ms);

    bool hasNames = student.getHasNamesForClasses();
    bool hasGrades = student.getHasGradesForClasses();

    auto const classes = student.getClasses();

    if (hasNames && hasGrades)
    {
        stream << "\nThe names & grades of those classes:\n";
        std::this_thread::sleep_for(500ms);
        int i = 1;
        for (Class const &clas : classes)
        {
            stream << "\n";
            if (clas.name == "")
                stream << i
                       << " (no name assigned)";
            else
                stream << clas.name;
            stream << " : ";
            if (clas.grade == -1)
                stream << "(no grade assigned)";
            else
                stream << clas.grade;
            i++;
            std::this_thread::sleep_for(500ms);
        }
    }
    else if (hasNames)
    {
        stream << "\nThis student has no grades for their classes (yet).\n";
        std::this_thread::sleep_for(500ms);
        stream << "\nThe names of those classes:\n";
        std::this_thread::sleep_for(500ms);
        int i = 1;
        for (Class const &clas : classes)
        {
            stream << "\n";
            if (clas.name == "")
                stream << i
                       << " (no name assigned)";
            else
                stream << clas.name;
            std::this_thread::sleep_for(500ms);
        }
    }
    else if (hasGrades)
    {
        stream << "\nThis student has no names for their classes (yet).\n";
        std::this_thread::sleep_for(500ms);
        stream << "\nThe grades of those classes:\n";
        int i = 1;
        for (Class const &clas : classes)
        {
            stream << "\n"
                   << i << " : ";
            if (clas.grade == -1)
                stream << "(no grade assigned)";
            else
                stream << clas.grade;
            i++;
            std::this_thread::sleep_for(500ms);
        }
    }
    else
    {
        stream << "\nThis student has no names or grades for their classes (yet).\n";
    }
    stream << "\n\n\n";
    std::this_thread::sleep_for(500ms);
    return stream;
}
