#include "Input.hpp"

void Input::inputGrades(std::vector<Student> &students)
{
    // Insert logic to ask user which student they would like to work with
    inputGrades(students[1]);
}

void Input::inputGrades(Student &student)
{
    // Insert logic to ask user which class(es) they would like to edit
    student.setGradeForClass(0, 0);
}