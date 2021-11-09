#include "Edit.hpp"

void Edit::editStudents(std::vector<Student> &students)
{
    // insert logic to ask user which student they wish to edit
    editStudent(students[0]);
}
void Edit::editStudent(Student &student)
{
    // insert logic to ask user what they want to edit (name, class number, class name), or add/remove classes
    student.setName("");
    student.setNameOfClass(0, "");
}