## Entity Relationship Diagram

The Faculty Management System consists of four main entities: **Department, Faculty, Course, and Attendance**.

```mermaid
erDiagram
    DEPARTMENT ||--o{ FACULTY : "has"
    FACULTY ||--o{ ATTENDANCE : "has"
    FACULTY ||--o{ COURSE : "teaches"
    COURSE ||--o{ ATTENDANCE : "for"

    DEPARTMENT {
        int department_id PK
        string department_name
    }

    FACULTY {
        int faculty_id PK
        string name
        string email
        string phone
        string designation
        int department_id FK
    }

    COURSE {
        int course_id PK
        string course_name
        string course_code
        int faculty_id FK
    }

    ATTENDANCE {
        int attendance_id PK
        int faculty_id FK
        int course_id FK
        date attendance_date
        string status
    }
```

### Entity Relationships

* **Department → Faculty:** A department can have multiple faculty members, while each faculty member belongs to one department.
* **Faculty → Course:** A faculty member can teach multiple courses.
* **Faculty → Attendance:** A faculty member can have multiple attendance records.
* **Course → Attendance:** Each course can have multiple attendance records.
