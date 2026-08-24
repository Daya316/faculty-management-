#ifndef FACULTYMANAGER_H
#define FACULTYMANAGER_H

#include <vector>
#include "Faculty.h"

class FacultyManager
{
private:
    vector<Faculty> faculties;

public:
    void addFaculty();

    void displayAll();

    void searchFaculty();

    void updateFaculty();

    void deleteFaculty();

    void searchByDepartment();

    void markFacultyAttendance();

    void attendanceReport();

    void saveToFile();

    void loadFromFile();
};

#endif