# Emergency Ticket Priority Queue System (Python)

A smart automated medical triage management application utilizing a Binary Heap data layout to systematically schedule elements by task severity rather than dynamic insertion timestamps.

## 🚀 Performance Metrics
* **Heap Architecture**: Leverages Python's optimal `heapq` module ($O(\log N)$ inserts and $O(\log N)$ priority node extractions).
* **Min-Max Mapping Strategy**: Uses negative index value keys (`-severity`) to transform native low-value sorted Python arrays into highly responsive high-priority scheduling queues.
