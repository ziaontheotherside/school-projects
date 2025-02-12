# 🚆 MetroLines (UMBC Project)

MetroLines is a **Python-based metro system simulation** that allows users to create stations, trains, and connections between stations while planning trips along different train lines. This project was developed as part of **CMSC 201 – Computer Science I for Majors** at the **University of Maryland, Baltimore County (UMBC)**.

---

## 📜 **Project Overview**
The program simulates a **train network system** where:
- Users can **create stations and connect them** with metro lines.
- Trains can be **added and moved** along their designated routes.
- A **trip planner** helps users find a path between two stations.
- (Optional) **Extra credit**: Implementing a step functionality where trains move automatically.

---

## 🛠 **Technologies & Concepts Used**
- **Language**: Python 🐍
- **Data Structures**: **Dictionaries** (to store stations, trains, and connections)
- **Algorithms**:
  - **Graph traversal** for trip planning.
  - **Recursion** for finding paths between stations.
- **Object-Oriented Programming (OOP)** concepts.

---

## ✨ **Key Features**
✅ **Create stations** dynamically.  
✅ **Connect stations** with train lines.  
✅ **Plan trips** between stations (uses recursion).  
✅ **Manage trains**, track locations, and update movements.  
✅ (Optional) **Step functionality** for automated train movement.  

---

## 🎮 **How It Works**
### **Basic Commands**
| Command | Description |
|---------|------------|
| `create station [station_name]` | Adds a new station to the system. |
| `connect stations [station1] [station2] [line_name]` | Creates a connection between two stations. |
| `create train [train_id] [line_name] [starting_position]` | Adds a train to a specified line and station. |
| `plan trip [start_station] [end_station]` | Finds a travel route between two stations (recursive). |
| `step` | Moves all trains one step forward along their lines. |
| `display stations` | Lists all available stations. |
| `display trains` | Shows all trains and their positions. |
| `get station info [station_name]` | Displays details about a specific station. |
| `get train info [train_id]` | Shows details about a train’s position and line. |
| `exit` | Exits the program. |

---

## 📄 **Academic Integrity Notice**
🚨 **This project was completed as part of UMBC's CMSC 201 coursework.**  
Per academic policies, copying my solution is strictly prohibited.

---

### ✨ **Final Thoughts**
MetroLines is a **great demonstration of recursion, graph traversal, and object-oriented design** in Python. The project builds a foundation for larger simulations and real-world transit system modeling.  

🚀 **Thank you for reviewing my project!**  
If you have any questions, feel free to reach out. 😊
