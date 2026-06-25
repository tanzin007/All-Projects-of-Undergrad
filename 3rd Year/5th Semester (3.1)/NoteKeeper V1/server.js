const express = require('express');
const http = require('http');
const { Server } = require('socket.io');
const path = require('path');
const fs = require('fs');

const app = express();
const server = http.createServer(app);
const io = new Server(server);

// Automatically generate package.json if it doesn't exist to save user's time
if (!fs.existsSync(path.join(__dirname, 'package.json'))) {
    const pkg = { name: "smart-notekeeper", version: "1.0.0", main: "server.js", dependencies: { "express": "^4.19.2", "socket.io": "^4.7.5" } };
    fs.writeFileSync(path.join(__dirname, 'package.json'), JSON.stringify(pkg, null, 2));
}

// Serve the index.html file on root request
app.get('/', (req, res) => {
    res.sendFile(path.join(__dirname, 'index.html'));
});

// WebSocket Configuration for Real-time Multi-window Sync
io.on('connection', (socket) => {
    // Listen for note updates from any client window
    socket.on('sync-notes', (notes) => {
        // Broadcast the updated notes to all other active windows immediately
        socket.broadcast.emit('update-notes', notes);
    });
});

const PORT = 3000;
server.listen(PORT, () => {
    console.log(`🚀 Smart NoteKeeper running at: http://localhost:${PORT}`);
    console.log(`💡 Open this link in 2 different browser tabs to see Real-time Sync!`);
});
