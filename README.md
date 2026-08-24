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
