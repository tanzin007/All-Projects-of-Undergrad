from flask import Flask, request, jsonify, render_template_string
import pandas as pd
import json
import os

app = Flask(__name__)
DATA_FILE = 'expenses.json'

# Initialize an empty storage file if it doesn't exist
if not os.path.exists(DATA_FILE):
    with open(DATA_FILE, 'w') as f:
        json.dump([], f)

@app.route('/')
def home():
    # Serve the index.html directly from the backend script
    with open('index.html', 'r', encoding='utf-8') as f:
        return render_template_string(f.read())

@app.route('/add-expense', methods=['POST'])
def add_expense():
    """Adds a new transaction log and appends it to the JSON file."""
    data = request.json
    with open(DATA_FILE, 'r+') as f:
        expenses = json.load(f)
        expenses.append({
            "category": data['category'],
            "amount": float(data['amount']),
            "month": data['month'] # Format: YYYY-MM
        })
        f.seek(0)
        json.dump(expenses, f, indent=4)
    return jsonify({"message": "Expense logged successfully!"})

@app.route('/analytics', methods=['GET'])
def get_analytics():
    """Processes historical data via Pandas to output chart values and insights."""
    with open(DATA_FILE, 'r') as f:
        data = json.load(f)
        
    if not data:
        return jsonify({"labels": [], "values": [], "alert": "No data logged yet."})

    # Load data into Pandas DataFrame for swift manipulation
    df = pd.DataFrame(data)
    
    # 1. Grouping by category for the pie chart
    category_totals = df.groupby('category')['amount'].sum().to_dict()
    
    # 2. Predictive Alert Logic based on monthly trend
    monthly_totals = df.groupby('month')['amount'].sum()
    alert_msg = "Keep logging transactions to unlock automated trend insights."
    
    if len(monthly_totals) >= 2:
        last_month = monthly_totals.iloc[-2]
        current_month = monthly_totals.iloc[-1]
        
        # Calculate percentage difference between the last two months
        change = ((current_month - last_month) / last_month) * 100
        if change > 10:
            alert_msg = f"⚠️ Alert: Your spending increased by {change:.1f}% compared to last month! Consider limiting luxury expenses."
        elif change < 0:
            alert_msg = f"🎉 Great job! Your spending dropped by {abs(change):.1f}% compared to last month."
        else:
            alert_msg = "ℹ️ Stable Trend: Your monthly budget configuration is currently well-balanced."

    return jsonify({
        "labels": list(category_totals.keys()),
        "values": list(category_totals.values()),
        "alert": alert_msg
    })

if __name__ == '__main__':
    app.run(debug=True, port=5000)
