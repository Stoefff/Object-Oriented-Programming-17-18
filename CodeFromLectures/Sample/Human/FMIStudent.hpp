#ifndef __FMI_STUDENT_HEADER_INCLUDED_
#define __FMI_STUDENT_HEADER_INCLUDED_

#include "Student.hpp"
#include "Employee.hpp"

class FMIStudent : public Employee, public Student
{
public:
    FMIStudent(const char* name, int fn, double sal)
        : Human(name)
        , Student(fn, name)
        , Employee(sal, name)
    {
    }

    virtual void info()const
    {
        cout << "E-e-e-eh, FMI..." << endl;
        Student::info();
        Employee::info();
    }
};

#endif // __FMI_STUDENT_HEADER_INCLUDED_
