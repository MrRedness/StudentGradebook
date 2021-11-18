#include "Student.hpp"

namespace Edit
{
    void editStudents(std::vector<Student> &students);
    void editStudent(Student &student);
    void editStudentName(Student &student);
    void editStudentClasses(Student &student);
    Class& getClass(Student &student) const;
    void addClass(Student &student);
    void editClass(Class &clas);
    void moveClass(Class &clas);
    void deleteClass(Class &clas);
}