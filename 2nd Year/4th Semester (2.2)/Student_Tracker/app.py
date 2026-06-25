from flask import Flask, request, jsonify
import sqlite3

app = Flask(__name__)
DB_FILE = "database.db"

def init_db():
    """Initializes the database and creates mandatory tables with normalized structure."""
    with sqlite3.connect(DB_FILE) as conn:
        cursor = conn.cursor()
        
        # 1. Students Table
        cursor.execute('''CREATE TABLE IF NOT EXISTS students (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            name TEXT NOT NULL,
            roll_no TEXT UNIQUE NOT NULL
        )''')
        
        # 2. Courses Table
        cursor.execute('''CREATE TABLE IF NOT EXISTS courses (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            course_code TEXT UNIQUE NOT NULL,
            course_name TEXT NOT NULL
        )''')
        
        # 3. Marks Table (Links Students and Courses)
        cursor.execute('''CREATE TABLE IF NOT EXISTS marks (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            student_id INTEGER,
            course_id INTEGER,
            marks_obtained REAL,
            FOREIGN KEY(student_id) REFERENCES students(id),
            FOREIGN KEY(course_id) REFERENCES courses(id)
        )''')
        
        # 4. Attendance Table (Tracks daily attendance)
        cursor.execute('''CREATE TABLE IF NOT EXISTS attendance (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            student_id INTEGER,
            date TEXT NOT NULL,
            status TEXT CHECK(status IN ('Present', 'Absent')),
            FOREIGN KEY(student_id) REFERENCES students(id)
        )''')
        
        conn.commit()

# --- CRUD Operations ---

@app.route('/add-student', methods=['POST'])
def add_student():
    """CREATE: Adds a new student to the database."""
    data = request.json
    with sqlite3.connect(DB_FILE) as conn:
        cursor = conn.cursor()
        cursor.execute("INSERT INTO students (name, roll_no) VALUES (?, ?)", 
                       (data['name'], data['roll_no']))
        conn.commit()
    return jsonify({"message": "Student added successfully!"}), 201

# --- Complex SQL Queries (Reports) ---

@app.route('/student-reportcard', methods=['GET'])
def get_report_card():
    """
    COMPLEX QUERY: Computes GPA/Average Marks and Attendance Percentage for each student.
    Uses multi-table JOINs, GROUP BY, and Aggregate functions (AVG, COUNT).
    """
    with sqlite3.connect(DB_FILE) as conn:
        cursor = conn.cursor()
        
        query = """
            SELECT 
                s.id,
                s.name,
                s.roll_no,
                ROUND(AVG(m.marks_obtained), 2) AS average_marks,
                ROUND((COUNT(CASE WHEN a.status = 'Present' THEN 1 END) * 100.0 / COUNT(a.id)), 2) AS attendance_percentage
            FROM students s
            LEFT JOIN marks m ON s.id = m.student_id
            LEFT JOIN attendance a ON s.id = a.student_id
            GROUP BY s.id
        """
        cursor.execute(query)
        rows = cursor.fetchall()
        
    result = []
    for row in rows:
        result.append({
            "student_id": row[0],
            "name": row[1],
            "roll_no": row[2],
            "avg_marks": row[3] if row[4] is not None else 0,
            "attendance_pct": row[4] if row[5] is not None else 0
        })
    return jsonify(result)

if __name__ == '__main__':
    init_db()
    app.run(debug=True, port=5000)
