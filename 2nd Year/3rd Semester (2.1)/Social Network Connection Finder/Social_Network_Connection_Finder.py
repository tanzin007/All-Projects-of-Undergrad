from collections import deque

class SocialNetwork:
    def __init__(self):
        # Graph represented as an Adjacency List (Dictionary mapping strings to lists)
        self.network = {}

    def add_user(self, name):
        if name not in self.network:
            self.network[name] = []

    def add_connection(self, user1, user2):
        """Creates a mutual bidirectional friendship connection."""
        self.add_user(user1)
        self.add_user(user2)
        if user2 not in self.network[user1]:
            self.network[user1].append(user2)
        if user1 not in self.network[user2]:
            self.network[user2].append(user1)

    def find_shortest_connection(self, start, target):
        """Uses BFS to mathematically find the shortest connection path."""
        if start not in self.network or target not in self.network:
            return None
        
        # Queue stores tuples of: (current_node, path_taken_so_far)
        queue = deque([(start, [start])])
        visited = set([start])

        while queue:
            current_user, path = queue.popleft()

            if current_user == target:
                return path

            for neighbor in self.network[current_user]:
                if neighbor not in visited:
                    visited.add(neighbor)
                    queue.append((neighbor, path + [neighbor]))
        return None

    def display_network(self):
        print("\n--- Social Graph Directory ---")
        for user, friends in self.network.items():
            print(f"👤 {user} is connected with: {', '.join(friends) if friends else 'None'}")

def main():
    sns = SocialNetwork()
    # Pre-loading mock social platform connections
    sns.add_connection("Alice", "Bob")
    sns.add_connection("Bob", "Charlie")
    sns.add_connection("Alice", "David")
    sns.add_connection("David", "Ethan")
    sns.add_connection("Ethan", "Charlie") # Creates multiple paths to Charlie
    sns.add_connection("Charlie", "Farhan")

    while True:
        sns.display_network()
        print("\nOptions:\n1. Search Degrees of Connection (BFS)\n2. Add New Friendship\n3. Exit")
        choice = input("Enter choice (1-3): ").strip()

        if choice == "1":
            p1 = input("Enter Source Person Name: ").strip()
            p2 = input("Enter Target Person Name: ").strip()
            path = sns.find_shortest_connection(p1, p2)
            
            if path:
                print(f"\n✅ Connection Found: {' ➡️ '.join(path)}")
                print(f"Degrees of Separation: {len(path) - 1}")
            else:
                print("\n❌ No mutual connection exists between them.")
        elif choice == "2":
            p1 = input("Enter First Person: ").strip()
            p2 = input("Enter Second Person: ").strip()
            if p1 and p2:
                sns.add_connection(p1, p2)
                print(f"\n🎉 {p1} and {p2} are now connected!")
        elif choice == "3":
            break
        else:
            print("\n❌ Invalid choice.")

if __name__ == "__main__":
    main()
