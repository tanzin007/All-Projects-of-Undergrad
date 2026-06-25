import os
import time
import random

def print_bars(data, current_indices=[]):
    """Clears terminal and prints bars based on array values."""
    os.system('cls' if os.name == 'nt' else 'clear')
    print("--- Sorting Algorithm Visualizer ---\n")
    for i, val in enumerate(data):
        # Highlight elements currently being compared
        if i in current_indices:
            print(f"{val:02d} | " + "█" * val + " 👈")
        else:
            print(f"{val:02d} | " + "░" * val)
    print("\n")
    time.sleep(0.1)

def bubble_sort(data):
    """Sorts data using Bubble Sort algorithm with animation."""
    n = len(data)
    for i in range(n):
        for j in range(0, n - i - 1):
            print_bars(data, [j, j + 1]) # Animate comparison
            if data[j] > data[j + 1]:
                data[j], data[j + 1] = data[j + 1], data[j] # Swap
                print_bars(data, [j, j + 1])

# Generate a random list of 15 integers between 3 and 25
random_list = random.sample(range(3, 26), 15)

print_bars(random_list)
time.sleep(1) # Pause before starting
bubble_sort(random_list)

print("=======================================")
# Final print with no active highlight indices
print_bars(random_list, [])
print("🎉 SUCCESS! Data Array Sorted Perfectly!")
print("=======================================")
