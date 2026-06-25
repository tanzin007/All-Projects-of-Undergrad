# Student Result & Attendance Tracker

An advanced DBMS-focused backend system that tracks student academic performance and daily attendance. This application highlights advanced relational queries using SQL aggregations, conditional counting, and grouping.

## 🚀 Features
- **Student Enrollment:** Easily add new student records with unique identifiers.
- **Complex SQL Aggregations:** Utilizes `AVG()` and `GROUP BY` to calculate real-time GPA and cumulative grades.
- **Conditional Query Logic:** Uses `COUNT(CASE WHEN...)` inside SQL to dynamically compute attendance percentages for each individual student.
- **Automated Mock Database:** Includes a standalone seed script to populate testing data with one click.

## 🛠️ Tech Stack
- **Language:** Python 3
- **Framework:** Flask
- **Database:** SQLite3

## 📁 Project Structure
```text
Student_Tracker_DBMS/
├── app.py              # Main Flask application and SQL routes
├── test_data.py        # Seed script to inject mock database entries
├── database.db         # Local SQLite database (Ignored by Git)
├── .gitignore          # Keeps build and database files out of GitHub
└── README.md           # Project documentation
```

## ⚙️ Setup & Installation

1. **Navigate to the project folder:**
   ```bash
   cd Semester_2.2/Student_Tracker_DBMS
   ```

2. **Install Flask:**
   ```bash
   pip install flask
   ```

3. **Seed Mock Data into Database:**
   ```bash
   python test_data.py
   ```

4. **Start the Project:**
   ```bash
   python app.py
   ```
   The backend will launch at `http://127.0.0`.

## 📡 API Evaluation

| Method | Endpoint | Query Operations Involved |
| :--- | :--- | :--- |
| `POST` | `/add-student` | Standard INSERT CRUD |
| `GET` | `/student-reportcard` | Advanced `LEFT JOIN`, `GROUP BY`, `AVG()`, `COUNT()` |

### Expected Output Structure from `/student-reportcard`:
```json
[
  {
    "student_id": 1,
    "name": "Alice Johnson",
    "roll_no": "S101",
    "avg_marks": 87.75,
    "attendance_pct": 66.67
  }
]
```
