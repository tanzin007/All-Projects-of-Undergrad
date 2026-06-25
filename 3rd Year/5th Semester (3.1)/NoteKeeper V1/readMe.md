# ⚡ Smart NoteKeeper Dashboard

A high-performance, eye-catching, and lightweight smart notebook application built for modern web browsers. This project demonstrates core concepts of **Web/Mobile App Development** including real-time full-duplex WebSocket communication, state persistence, and dynamic front-end text processing—all achieved **without requiring any external database installations**.

---

## 🚀 Key Features

- **Premium UI Architecture:** Styled with a modern Cyber Dark theme featuring premium Neon Glassmorphism visual elements.
- **Real-Time Synchronization Engine:** Uses `Socket.io` (WebSockets) to instantly mirror updates across multiple active browser windows or client tabs without a single page reload.
- **Zero-Dependency Local Persistence:** Leverages native browser `LocalStorage` to save your data permanently. Your notes remain completely safe even if you close or reboot your computer.
- **Automated Linguistic Tag Engine:** Features a smart JavaScript parser that automatically scans the first few words of your inputs to generate automated category hashtags (e.g., `#Study`, `#General`).

---

## 📁 Minimalist Project Structure

The entire application runs on an efficient, ultra-lightweight architecture consisting of just two primary files:

```text
NoteKeeper V1/
├── server.js          # Unified Node.js environment & WebSocket server
├── index.html         # User Interface, Premium Styling & Frontend logic
└── README.md          # Project documentation profile
```

---

## 🛠️ Tech Stack Included

- **Backend Platform:** Node.js
- **Network Routing Framework:** Express.js
- **Real-time Engine:** Socket.io (WebSockets Protocol)
- **Frontend Stack:** HTML5 / CSS3 (Flexbox & Grid Layouts) / Vanilla JavaScript (ES6+)

---

## ⚙️ How to Setup & Run locally

To spin up this repository on your local computer using **VS Code**, follow these steps:

1. **Open the project folder** inside your VS Code workspace terminal.
2. **Install the required packages** by running the following command:
   ```bash
   npm install express socket.io
   ```
3. **Launch the backend execution server** using Node:
   ```bash
   node server.js
   ```
4. **Access the application Dashboard** by opening your web browser and navigating to:
   ```text
   http://localhost:3000
   ```

💡 **Testing Real-Time Sync:** To evaluate the WebSockets architecture, open `http://localhost:3000` in **two different browser tabs side-by-side**. Type or delete a note in one window, and watch it instantly update in the other window in real-time!

---

## 📊 Evaluation & Concepts Demonstrated

This project successfully implements critical engineering benchmarks for **Semester 3.1 (Web/Mobile App Development)** evaluation:
1. **API State Delivery:** Demonstrates serving and distributing native files from a backend Node core.
2. **Event-Driven WebSockets:** Highlights bidirectional event pipelines via `socket.emit()` and `socket.on()`.
3. **Data Security & Storage:** Demonstrates client-side sandbox persistent storage caching routines.
