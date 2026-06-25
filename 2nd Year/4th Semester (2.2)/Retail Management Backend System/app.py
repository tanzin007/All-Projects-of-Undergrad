from flask import Flask, request, jsonify
import sqlite3

app = Flask(__name__)
DB_FILE = "database.db"

def init_db():
    """database and table"""
    with sqlite3.connect(DB_FILE) as conn:
        cursor = conn.cursor()
        # product table
        cursor.execute('''CREATE TABLE IF NOT EXISTS products (
            id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, price REAL, stock INTEGER)''')
        # customer table
        cursor.execute('''CREATE TABLE IF NOT EXISTS customers (
            id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, email TEXT UNIQUE)''')
        # order table (Complex Relationship)
        cursor.execute('''CREATE TABLE IF NOT EXISTS orders (
            id INTEGER PRIMARY KEY AUTOINCREMENT, customer_id INTEGER, 
            product_id INTEGER, quantity INTEGER, 
            FOREIGN KEY(customer_id) REFERENCES customers(id),
            FOREIGN KEY(product_id) REFERENCES products(id))''')
        conn.commit()

# --- CRUD Operations ---

@app.route('/add-product', methods=['POST'])
def add_product():
    """CREATE: add new product"""
    data = request.json
    with sqlite3.connect(DB_FILE) as conn:
        cursor = conn.cursor()
        cursor.execute("INSERT INTO products (name, price, stock) VALUES (?, ?, ?)", 
                       (data['name'], data['price'], data['stock']))
        conn.commit()
    return jsonify({"message": "Product added successfully!"}), 201

@app.route('/products', methods=['GET'])
def get_products():
    """READ: সsee all product"""
    with sqlite3.connect(DB_FILE) as conn:
        cursor = conn.cursor()
        cursor.execute("SELECT * FROM products")
        products = cursor.fetchall()
    return jsonify(products)

# --- Complex SQL Query (JOIN) ---

@app.route('/order-details', methods=['GET'])
def get_order_details():
    """JOIN: make joint report"""
    with sqlite3.connect(DB_FILE) as conn:
        cursor = conn.cursor()
        query = """
            SELECT 
                orders.id AS order_id,
                customers.name AS customer_name,
                products.name AS product_name,
                orders.quantity,
                (orders.quantity * products.price) AS total_price
            FROM orders
            JOIN customers ON orders.customer_id = customers.id
            JOIN products ON orders.product_id = products.id
        """
        cursor.execute(query)
        report = cursor.fetchall()
    
    # formated output
    result = []
    for row in report:
        result.append({
            "order_id": row[0],
            "customer_name": row[1],
            "product_name": row[2],
            "quantity": row[3],
            "total_bill": row[4]
        })
    return jsonify(result)

if __name__ == '__main__':
    init_db()
    app.run(debug=True, port=5000)
