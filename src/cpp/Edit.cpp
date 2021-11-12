#include "Edit.hpp"
#include "MrRed.hpp"

void Edit::editStudents(std::vector<Student> &students)
{
    using namespace std::chrono_literals;
    cOutAndWait("List of students", 1);
    unsigned int i = 1;
    for (Student &stu : students)
    {
        std::cout << i << " : " << stu.getName() << std::endl;
        std::this_thread::sleep_for(.5s);
        i++;
    }
    std::cout << "Which student would you like to edit? Enter the number here\n:";
    editStudent(students[cinInt(1, students.size())]);
}
void Edit::editStudent(Student &student)
{
    // insert logic to ask user what they want to edit (name, class number, class name), or add/remove classes
    student.setName("");
    student.setNameOfClass(0, "");
}