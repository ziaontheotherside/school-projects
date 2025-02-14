# ⚙️ Process Manager

Process Manager is a **C++ process scheduling simulation** that models how a computer handles multiple processes using a **templated stack-based structure**. It simulates multi-threading by organizing processes into **stacks**, with each thread managing a queue of processes.  

This project was developed for **CMSC 202 – Computer Science II** at **UMBC (University of Maryland, Baltimore County).**  

This project demonstrates **templated data structures, object-oriented programming (OOP), linked lists, and multi-threaded process management logic**.

---

## 📜 **Project Overview**
### **What This Project Does**
✅ **Simulates a multi-threaded process scheduler** using stacks.  
✅ **Implements a templated linked list stack (Lstack)** for managing process execution order.  
✅ **Reads process data from an input file** and organizes it into threads.  
✅ **Executes process threads sequentially**, removing them from stacks as they complete.  
✅ **Calculates the total execution time** for each thread.  
✅ **Implements memory management to prevent memory leaks.**  

This project **demonstrates structured C++ programming, data structures, and system simulation**.

---

## 🛠 **Key Skills Demonstrated**
- **C++ Development**: Multi-file project structure, makefiles, and modular code.
- **Templated Data Structures**: Implemented a **custom templated stack (Lstack)**.
- **Object-Oriented Programming (OOP)**:
  - **Encapsulation & Classes** (`Process`, `Processor`, `Lstack`).
  - **Operator Overloading** (copy constructors and assignment operators).
- **Linked Lists & Memory Management**:
  - **Custom singly linked list** adapted as a **LIFO stack**.
  - **Dynamic memory allocation** (`new` and `delete` management).
- **Process Scheduling Simulation**:
  - **Multi-threaded execution model** (1-6 concurrent threads).
  - **Processes organized into stacks** with dependencies based on `call ID`.

---

## 🎮 **How It Works (Simplified)**
### **Program Functionality**
| Feature | Description |
|---------|------------|
| **📂 Load Process Data** | Reads process details from `proj5_dataX.txt` and organizes them into threads. |
| **📊 Display Threads** | Lists all active threads and their queued processes. |
| **⚙️ Execute Threads** | Simulates execution by removing processes from stacks. |
| **⏱️ Calculate Execution Time** | Determines the time taken for each thread to complete. |
| **🚪 Exit Program** | Allows the user to quit at any time. |

### **Example Execution**
1️⃣ **User starts the program and loads a process data file** (e.g., `proj5_data1.txt`).  
2️⃣ **Processes are assigned to threads based on thread count (1-6).**  
3️⃣ **User selects "Display Threads" to see active process stacks.**  
4️⃣ **User selects "Start Thread Execution" to process threads sequentially.**  
5️⃣ **Total execution time for each thread is displayed.**  
6️⃣ **User can quit or restart with a new data file.**  

---

## 🚀 **Why This Matters**
This project highlights my ability to:  
✔️ **Implement complex data structures (linked lists, stacks) from scratch.**  
✔️ **Develop modular, object-oriented C++ applications.**  
✔️ **Manage memory effectively to prevent leaks in dynamic structures.**  
✔️ **Simulate real-world process scheduling in multi-threaded environments.**  

It showcases skills relevant to **systems programming, software engineering, and data structures**.

---

## 📜 **Project Context**
🚨 **This project was completed as part of UMBC's CMSC 202 coursework.**  
Per academic policies, copying my solution is strictly prohibited.

---

### ✨ **Final Thoughts**
Process Manager is a **C++ process scheduling simulation that demonstrates templated data structures, linked lists, and multi-threaded processing concepts**.  

If you'd like to discuss my **C++ skills, data structures expertise, or problem-solving approach**, feel free to connect! 🚀😊
