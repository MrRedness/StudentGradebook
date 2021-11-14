#pragma once
#include "PCH.hpp"
#include <string_view>

struct Class
{
    std::string name;
    int grade;

    Class(std::string_view name_, int grade_) // allows conversion from string_view
        : name { name_ }
        , grade { grade_ }
    { }
};

class Student
{
private:
    std::string name;
    bool hasNamesForClasses;
    bool hasGradesForClasses;
    std::vector<Class> classes;
    bool outOfBounds(std::size_t input);

public:
    static std::size_t const classLimit = 10;

    Student(std::string_view name, bool hasNamesForClasses, bool hasGradesForClasses, std::vector<Class> const &classes);

    std::string getName() const;
    std::size_t getNumberOfClasses() const;
    std::string getNameOfClass(std::size_t classNumber) const;
    std::size_t getClassPeriod(std::string_view className) const;
    // std::vector<Class> &getClasses();
    std::vector<Class> const &getClasses() const;

    bool getHasNamesForClasses() const;
    bool getHasGradesForClasses() const;

    void setName(std::string_view name);
    bool setNameOfClass(std::size_t classPeriod, std::string_view newName);
    bool setNameOfClass(std::string_view oldName, std::string_view newName);
    bool setGradeForClass(std::size_t classPeriod, int grade);
    bool setGradeForClass(std::string_view className, int grade);

    bool addClass();
    bool addClass(std::size_t classPeriod); // Moves everything above classPeriod forward one
    bool addClass(std::string_view className);
    bool addClass(std::size_t classPeriod, std::string_view className);

    bool removeClass();
    bool removeClass(std::size_t classPeriod);
    bool removeClass(std::string_view className);
};

std::ostream &operator<<(std::ostream &stream, Student const &student);
