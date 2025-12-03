# Deadlock Detection Toolkit
 A C++ implementation of the Banker's Algorithm to detect deadlocks in an operating system.
 This project is part of the CSE316 Operating System Course Assignment(CA2).

 ---

## 📌 Overview

Deadlock occurs in a system when multiple processes are waiting indefinitely for resources held by each other.
This toolkit helps analays system status using the **Banker's Safety Algorithm**, and determines:

- Whether the system is in a **Safe State**
- A valid **Safe Sequence** (if it exists)
- Or if a **Deadlock is Detected**

The program takes:
- Allocation Matrix
- Maximum Need Matrix
- Available Resources

And calculates:
- Need Matrix
- Work Vector
- Safe Sequence

---

## 🧠 Features

✔ Input support for multiple processes and resources
✔ Automatic NEED matrix calculation  
✔ Implementation of Banker's Safety Algorithm
✔ Detection of:
 - Safe State
 - Deadlock State
✔ Clear formatted output
✔ Handles any number of processes and resources

---

## 🛠 Technologies Used

- **C++**
- **Vectors (STL)**
- **Dynamic Matrix Handling**
- **Git & GitHub (Version Control)**

---

## 📥 How to Run

### **1. Clone the repository**

```bash
git clone https://github.com/inshu5757/deadlock-detection-toolkit.git


