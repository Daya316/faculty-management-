#include "FacultyManager.h"
#include <fstream>
// Function to add a new faculty member
void FacultyManager::addFaculty()
{
    int id, age;
    string name, dept;
    double salary;

    cout << "Enter ID: ";
    cin >> id;

    cin.ignore();

    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Enter Age: ";
    cin >> age;

    cin.ignore();

    cout << "Enter Department: ";
    getline(cin, dept);

    cout << "Enter Salary: ";
    cin >> salary;

    faculties.push_back(
        Faculty(id, name, age, dept, salary));

    cout << "\nFaculty Added Successfully\n";
}

// Function to display all faculty members
void FacultyManager::displayAll()
{
    if (faculties.empty())
    {
        cout << "\nNo Records Found\n";
        return;
    }

    for (auto &f : faculties)
    {
        f.display();
    }
}
// Function to search for a faculty member by ID
void FacultyManager::searchFaculty()
{
    int id;

    cout << "Enter Faculty ID: ";
    cin >> id;

    for (auto &f : faculties)
    {
        if (f.getId() == id)
        {
            f.display();
            return;
        }
    }

    cout << "\nFaculty Not Found\n";
}
// Function to update a faculty member's details
void FacultyManager::updateFaculty()
{
    int id;

    cout << "Enter Faculty ID: ";
    cin >> id;

    for (auto &f : faculties)
    {
        if (f.getId() == id)
        {
            string name, dept;
            int age;
            double salary;

            cin.ignore();

            cout << "Enter New Name: ";
            getline(cin, name);

            cout << "Enter New Age: ";
            cin >> age;

            cin.ignore();

            cout << "Enter New Department: ";
            getline(cin, dept);

            cout << "Enter New Salary: ";
            cin >> salary;

            f = Faculty(id,
                        name,
                        age,
                        dept,
                        salary,
                        f.getAttendance());

            cout << "\nFaculty Updated Successfully\n";
            return;
        }
    }

    cout << "\nFaculty Not Found\n";
}


// Function to delete a faculty member by ID
void FacultyManager::deleteFaculty()
{
    int id;

    cout << "Enter Faculty ID: ";
    cin >> id;

    for (auto it = faculties.begin();
         it != faculties.end();
         it++)
    {
        if (it->getId() == id)
        {
            faculties.erase(it);

            cout << "\nFaculty Deleted Successfully\n";

            return;
        }
    }

    cout << "\nFaculty Not Found\n";
}

// Function to search for faculty members by department
void FacultyManager::searchByDepartment()
{
    string dept;

    cin.ignore();

    cout << "Enter Department: ";

    getline(cin, dept);

    bool found = false;

    for (auto &f : faculties)
    {
        if (f.getDepartment() == dept)
        {
            f.display();

            found = true;
        }
    }

    if (!found)
    {
        cout << "\nNo Faculty Found\n";
    }
}
// Function to generate an attendance report for all faculty members
void FacultyManager::markFacultyAttendance()
{
    int id;

    cout << "Enter Faculty ID: ";
    cin >> id;

    for (auto &f : faculties)
    {
        if (f.getId() == id)
        {
            f.markAttendance();

            cout << "\nAttendance Marked\n";
            return;
        }
    }

    cout << "\nFaculty Not Found\n";
}
// Function to generate an attendance report for all faculty members
void FacultyManager::attendanceReport()
{
    cout << "\n===== ATTENDANCE REPORT =====\n";

    for (auto &f : faculties)
    {
        cout << "\nID : "
             << f.getId();

        cout << "\nName : "
             << f.getName();

        cout << "\nAttendance : "
             << f.getAttendance();

        cout << "\n-------------------\n";
    }
}


// Function to save faculty data to a file

void FacultyManager::saveToFile()
{
    ofstream file("faculty.txt");

    for (auto &f : faculties)
    {
        file << f.getId() << ","
             << f.getName() << ","
             << f.getAge() << ","
             << f.getDepartment() << ","
             << f.getSalary() << ","
             << f.getAttendance()
             << endl;
    }

    file.close();
}


// Function to load faculty data from a file
void FacultyManager::loadFromFile()
{
    faculties.clear();

    ifstream file("faculty.txt");

    int id, age, attendance;
    string name, dept;
    double salary;
    char comma;

    while (file >> id >> comma)
    {
        getline(file, name, ',');

        file >> age >> comma;

        getline(file, dept, ',');

        file >> salary >> comma;

        file >> attendance;

        file.ignore();

        faculties.push_back(
            Faculty(id,
                    name,
                    age,
                    dept,
                    salary,
                    attendance));
    }

    file.close();
}