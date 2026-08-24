#ifndef FACULTY_H
#define FACULTY_H

#include "Person.h"

class Faculty : public Person
{
private:
    string department;
    double salary;
    int attendanceDays;

public:
    Faculty() {}

    Faculty(int id,
            string name,
            int age,
            string department,
            double salary,
            int attendanceDays = 0)
        : Person(id, name, age)
    {
        this->department = department;
        this->salary = salary;
        this->attendanceDays = attendanceDays;
    }

    void display()
    {
        cout << "\n============================";
        cout << "\nID         : " << id;
        cout << "\nName       : " << name;
        cout << "\nAge        : " << age;
        cout << "\nDepartment : " << department;
        cout << "\nSalary     : " << salary;
        cout << "\nAttendance : " << attendanceDays << " Days";
        cout << "\n============================\n";
    }

    string getName()
    {
        return name;
    }

    int getAge()
    {
        return age;
    }

    string getDepartment()
    {
        return department;
    }

    double getSalary()
    {
        return salary;
    }

    int getAttendance()
    {
        return attendanceDays;
    }

    void markAttendance()
    {
        attendanceDays++;
    }
};

#endif