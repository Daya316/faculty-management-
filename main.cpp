#include "FacultyManager.h"

int main()
{
    FacultyManager manager;

    manager.loadFromFile();

    int choice;

    do
    {
        cout << "\n===== FACULTY MANAGEMENT SYSTEM =====\n";

        cout << "1. Add Faculty\n";
        cout << "2. Display All Faculty\n";
        cout << "3. Search Faculty\n";
        cout << "4. Update Faculty\n";
        cout << "5. Delete Faculty\n";
        cout << "6. Search By Department\n";
        cout << "7. Mark Attendance\n";
        cout << "8. Attendance Report\n";
        cout << "9. Save Data\n";
        cout << "10. Exit\n";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            manager.addFaculty();
            break;

        case 2:
            manager.displayAll();
            break;

        case 3:
            manager.searchFaculty();
            break;

        case 4:
            manager.updateFaculty();
            break;

        case 5:
            manager.deleteFaculty();
            break;

        case 6:
            manager.searchByDepartment();
            break;

        case 7:
            manager.markFacultyAttendance();
            break;

        case 8:
            manager.attendanceReport();
            break;

        case 9:
            manager.saveToFile();
            cout << "\nData Saved Successfully\n";
            break;

        case 10:
            manager.saveToFile();
            cout << "\nThank You\n";
            break;

        default:
            cout << "\nInvalid Choice\n";
        }

    } while (choice != 10);

    return 0;
}