# Inventory & Order Management System (E-Commerce Backend)

A robust backend REST API built for managing products, customers, and orders. This project demonstrates core Database Management System (DBMS) concepts including database normalization (3NF), foreign key constraints, table joins, and CRUD operations.

## 🚀 Features
- **Product Management:** Create and view items with real-time price and stock levels.
- **Database Normalization:** Structured into 3 separate tables (`products`, `customers`, `orders`) to eliminate data redundancy.
- **Complex SQL Joins:** Combines 3 tables using SQL `JOIN` to generate full customer purchase reports with automated bill calculations.
- **Relational Integrity:** Implements Foreign Keys to link customer transactions securely.

## 🛠️ Tech Stack
- **Language:** Python 3
- **Framework:** Flask (REST API)
- **Database:** SQLite3

## 📁 Project Structure
```text
Retail Management Backend System/
├── app.py              # Main backend application code
├── database.db         # SQLite database file (Auto-generated)
├── schema.sql          # SQL Schema backup & query references
└── README.md           # Project documentation
```

## ⚙️ Setup & Installation

1. **Clone or navigate to the folder:**
   ```bash
   cd Semester_2.2/Retail Management Backend System
   ```

2. **Install Dependencies:**
   ```bash
   pip install flask
   ```

3. **Run the Application:**
   ```bash
   python app.py
   ```
   The server will start running on `http://127.0.0`.

## 📡 API Endpoints & Testing

| Method | Endpoint | Description |
| :--- | :--- | :--- |
| `POST` | `/add-product` | Insert a new item into the inventory |
| `GET` | `/products` | Fetch all products available in stock |
| `GET` | `/order-details` | Fetch normalized orders report combining 3 tables |

### Sample JSON Payload for `/add-product`:
```json
{
  "name": "Wireless Mouse",
  "price": 25.99,
  "stock": 150
}
```
