#include <iostream>
#include <fstream>
#include <list>
#include <unordered_map>
#include <string>

using namespace std;

struct Task {
    int id;
    string name;
    bool isCompleted, isCancelled;
};

class TaskManager {
private:
    list<Task> tasks;                         // Stores the list of tasks
    unordered_map<int, list<Task>::iterator> taskMap;  // Maps task ID to list iterator
    int nextId;                               // ID counter for tasks

public:
    TaskManager() : nextId(1) {}

    void addTask(const string& taskName) {
        tasks.push_back({nextId, taskName, false});
        taskMap[nextId] = --tasks.end();  // Map the task ID to the newly added task
        cout << "Task added successfully!" << endl;
        ++nextId;
    }

    void displayTasks() const {
        if (tasks.empty()) {
            cout << "No tasks available." << endl;
        } else {
            cout << "Task List:" << endl;
            for (const auto& task : tasks) {
                cout << "ID: " << task.id << " | Task: " << task.name 
                     << " | Status: " << (task.isCompleted ? "Completed" : (task.isCancelled ? "Cancelled" : "Pending")) << endl;
            }
        }
    }

    void completeTask(int taskId) {
        auto it = taskMap.find(taskId);
        if (it != taskMap.end()) {
            it->second->isCompleted = true;
            cout << "Task marked as completed!" << endl;
        } else {
            cout << "Task not found!" << endl;
        }
    }

    void cancelTask(int taskId) {
        auto it = taskMap.find(taskId);
        if (it != taskMap.end()) {
            it->second->isCancelled = true;
            cout << "Task marked as cancelled!" << endl;
        } else {
            cout << "Task not found!" << endl;
        }
    }

    void deleteTask(int taskId) {
        auto it = taskMap.find(taskId);
        if (it != taskMap.end()) {
            tasks.erase(it->second);  // Erase the task from the list
            taskMap.erase(it);        // Remove task from the map
            cout << "Task deleted successfully!" << endl;
        } else {
            cout << "Task not found!" << endl;
        }
    }

    void saveToFile(const std::string &filename) {
        ofstream outFile(filename);
        if (outFile.is_open()) {
            for (const auto& task : tasks) {
                outFile << "ID: " << task.id << " | Task: " << task.name << " | Status: " << (task.isCompleted ? "Completed" : (task.isCancelled ? "Cancelled" : "Pending")) << endl;
            }
            outFile.close();
            cout << "Tasks saved to " << filename << std::endl;
        } else {
        cout << "Unable to open file " << filename << std::endl;
    }
}
};

int main() {
    TaskManager taskManager;
    int choice, id;
    string taskName;

    while (true) {
        cout << "-----------------------"<<endl;
        cout << "Task Manager Menu" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. Display Tasks" << endl;
        cout << "3. Complete Task" << endl;
        cout << "4. Cancel Task" << endl;
        cout << "5. Delete Task" << endl;
        cout << "6. Save to Memory File" << endl;
        cout << "7. Exit" << endl;
        cout << "-----------------------"<<endl;
        cout << "Enter your choice: ";
        cin >> choice;

if (choice == 1) {
            cout << "Enter task name: ";
            cin.ignore();
            getline(cin, taskName);
            taskManager.addTask(taskName);
        } else if (choice == 2) {
            taskManager.displayTasks();
        } else if (choice == 3) {
            cout << "Enter task ID to mark as completed: ";
            cin >> id;
            taskManager.completeTask(id);
        } else if (choice == 4) {
            cout << "Enter task ID to Cancel: ";
            cin >> id;
            taskManager.cancelTask(id);
        } else if (choice == 5) {
            cout << "Enter task ID to delete: ";
            cin >> id;
            taskManager.deleteTask(id);
        } else if (choice == 6) {
            cout << "File saved to memory" << endl;
            taskManager.saveToFile("memory.txt");
        } else if (choice == 7) {
            cout << "Exiting program..." << endl;
            break;
        } else {
            cout << "Invalid choice!" << endl;
            break;
        }
    }
    return 0;
}
