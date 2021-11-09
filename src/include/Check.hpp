#pragma once
#include "Student.hpp"

namespace Check
{
    void getStudentInfoFrom(std::vector<Student> const &students);
    void printAllStudentInfo(std::vector<Student> const &students);
    void getSpecificStudentInfo(std::vector<Student> const &students);
}