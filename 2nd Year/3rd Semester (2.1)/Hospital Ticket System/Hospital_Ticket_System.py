import heapq

class HospitalEmergencySystem:
    def __init__(self):
        # Min-Heap array storage
        self.patient_queue = []
        self.counter = 0 # Tie-breaker counter if two patients have same priority

    def register_patient(self, name, condition_severity):
        """
        Pushes patient with an inverted condition level to use min-heap as a max-heap.
        Severity Scale: 1 (Mild) to 5 (Critical/Life-Threatening)
        """
        if condition_severity < 1 or condition_severity > 5:
            print("❌ Invalid severity level! Use scale 1-5.")
            return

        # Python heap is a Min-Heap. 
        # Using negative severity so higher severity numbers (-5) become smallest values and jump to top.
        priority_value = -condition_severity 
        
        heapq.heappush(self.patient_queue, (priority_value, self.counter, name, condition_severity))
        print(f"\n🚑 Registered: '{name}' | Severity Level: {condition_severity}")
        self.counter += 1

    def treat_next_patient(self):
        """Pops and treats the highest priority patient from the binary heap structure."""
        if self.patient_queue:
            _, _, name, severity = heapq.heappop(self.patient_queue)
            print(f"\n🩺 Now Treating Patient: {name} (Severity Level: {severity})")
        else:
            print("\n✨ All patients have been treated. Emergency ward clear!")

    def display_queue(self):
        """Displays temporary raw patient states pending execution inside heap logic."""
        print("\n=======================================")
        print("     EMERGENCY ROOM PATIENT QUEUE      ")
        print("=======================================")
        if not self.patient_queue:
            print("No patients in queue.")
        else:
            # Sort a copy of the list to display in correct order of priority
            sorted_patients = sorted(self.patient_queue)
            for item in sorted_patients:
                print(f"Priority: [Level {item[3]}] 👤 Patient: {item[2]}")
        print("=======================================")

def main():
    hospital = HospitalEmergencySystem()
    # Pre-loading mock medical cases
    hospital.register_patient("John (Broken Arm)", 3)
    hospital.register_patient("Sara (Chest Pain)", 5)
    hospital.register_patient("Mike (Mild Fever)", 1)

    while True:
        hospital.display_queue()
        print("Options:\n1. Register New Patient\n2. Treat Next Critical Patient\n3. Exit")
        choice = input("Enter choice (1-3): ").strip()

        if choice == "1":
            name = input("Enter Patient Name & Symptoms: ").strip()
            try:
                severity = int(input("Enter Emergency Severity Level (1-Mild to 5-Critical): "))
                hospital.register_patient(name, severity)
            except ValueError:
                print("\n❌ Error: Please enter a valid number for severity.")
        elif choice == "2":
            hospital.treat_next_patient()
        elif choice == "3":
            break
        else:
            print("\n❌ Invalid option selected.")

if __name__ == "__main__":
    main()
