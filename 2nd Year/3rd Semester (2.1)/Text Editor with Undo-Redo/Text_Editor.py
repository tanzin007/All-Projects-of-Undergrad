import os

class TextEditor:
    def __init__(self):
        self.current_text = ""
        self.undo_stack = []  # Stores history for undo operations
        self.redo_stack = []  # Stores history for redo operations

    def write(self, new_text):
        """Adds new text and clears the redo stack since history changes."""
        self.undo_stack.append(self.current_text) # Push current state to undo
        self.redo_stack.clear() # Clear redo history on new action
        if self.current_text:
            self.current_text += " " + new_text
        else:
            self.current_text = new_text
        print(f"\n📝 Added text: '{new_text}'")

    def undo(self):
        """Reverts the last action using LIFO stack behavior."""
        if self.undo_stack:
            self.redo_stack.append(self.current_text) # Push current state to redo
            self.current_text = self.undo_stack.pop() # Pop from undo stack
            print("\n↩️ Undo successful!")
        else:
            print("\n❌ Nothing to undo!")

    def redo(self):
        """Restores the last undone action."""
        if self.redo_stack:
            self.undo_stack.append(self.current_text) # Push current state to undo
            self.current_text = self.redo_stack.pop() # Pop from redo stack
            print("\n🔁 Redo successful!")
        else:
            print("\n❌ Nothing to redo!")

    def display(self):
        """Displays the editor status and stack sizes for visualization."""
        print("\n=======================================")
        print("          TEXT EDITOR STATUS           ")
        print("=======================================")
        print(f"Current Content : \"{self.current_text}\"")
        print(f"Undo Stack Size : {len(self.undo_stack)} | Redo Stack Size : {len(self.redo_stack)}")
        print("=======================================")

def main():
    editor = TextEditor()
    while True:
        editor.display()
        print("Menu Choices:")
        print("1. Write Text\n2. Undo\n3. Redo\n4. Exit")
        choice = input("Enter choice (1-4): ").strip()

        if choice == "1":
            text_input = input("Type your word/sentence: ").strip()
            if text_input:
                editor.write(text_input)
        elif choice == "2":
            editor.undo()
        elif choice == "3":
            editor.redo()
        elif choice == "4":
            print("\nClosing Editor... Temporary buffer cleared!")
            break
        else:
            print("\n❌ Invalid choice! Please enter 1-4.")

if __name__ == "__main__":
    main()
