# Text Editor with Undo/Redo System (Python)

A console-based text utility implementing custom Undo/Redo features leveraging the Last-In-First-Out (LIFO) property of the Stack data structure.

## 🚀 Data Structure Architecture
* **Undo Operations**: Before modifying the buffer, the previous state is pushed onto the `undo_stack`. Calling undo pops the top item and restores it.
* **Redo Operations**: Undone states are temporarily held inside the `redo_stack`. Any new write action clears this stack to preserve linear timeline logic.
