import sqlite3

DB_FILE = "database.db"

def insert_sample_data():
    """Populates the database with test records to evaluate complex SQL joins."""
    with sqlite3.connect(DB_FILE) as conn:
        cursor = conn.cursor()
        
        # Insert Students
        cursor.executemany("INSERT OR IGNORE INTO students (id, name, roll_no) VALUES (?, ?, ?)", [
            (1, "Alice Johnson", "S101"),
            (2, "Bob Smith", "S102")
        ])
        
        # Insert Courses
        cursor.executemany("INSERT OR IGNORE INTO courses (id, course_code, course_name) VALUES (?, ?, ?)", [
            (1, "CSE-221", "Database Management Systems"),
            (2, "CSE-222", "Algorithms")
        ])
        
        # Insert Marks
        cursor.executemany("INSERT OR IGNORE INTO marks (student_id, course_id, marks_obtained) VALUES (?, ?, ?)", [
            (1, 1, 85.5), (1, 2, 90.0),
            (2, 1, 72.0), (2, 2, 65.5)
        ])
        
        # Insert Attendance
        cursor.executemany("INSERT OR IGNORE INTO attendance (student_id, date, status) VALUES (?, ?, ?)", [
            (1, "2026-06-01", "Present"), (1, "2026-06-02", "Present"), (1, "2026-06-03", "Absent"),
            (2, "2026-06-01", "Present"), (2, "2026-06-02", "Absent"), (2, "2026-06-03", "Absent")
        ])
        
        conn.commit()
    print("Sample data inserted successfully!")

if __name__ == '__main__':
    insert_sample_data()
