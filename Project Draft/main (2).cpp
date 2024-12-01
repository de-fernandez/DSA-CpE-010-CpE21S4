#include <iostream>
#include <fstream>
#include <list>
#include <unordered_map>
#include <string>
#include <ctime>
#include <iomanip>
#include <conio.h> // For getch() to hide password input

using namespace std;

// Function to clear the console screen
void clearConsole() {
#ifdef _WIN32
    system("cls"); // Windows-specific clear screen command
#else
    system("clear"); // Linux/macOS-specific clear screen command
#endif
}

// Function to display ASCII art
void displayAsciiArt(const string& art) {
    cout << art << endl;
}

// ASCII art for WELCOME
string welcomeArt = R"(
__        __   _                            _         
\ \      / /__| | ___ ___  _ __ ___   ___  | |_ ___   
 \ \ /\ / / _ \ |/ __/ _ \| '_ ` _ \ / _ \ | __/ _ \  
  \ V  V /  __/ | (_| (_) | | | | | |  __/ | || (_) | 
   \_/\_/ \___|_|\___\___/|_| |_| |_|\___|  \__\___/  
)";

// ASCII art for TASK MANAGER
string taskManagerArt = R"(
   _______         _        __  __                                
  |__   __|       | |      |  \/  |                               
     | | __ _ ___ | |/ /   | \  / | ___ _ __   ___  __ _  ___ _ __ 
     | |/ _` / __||   /    | |\/| |/ _ \ '_ \ / _ \/ _` |/ _ \ '__|
     | | (_| \__ \| |\ \   | |  | |  __/ | | |  __/ (_| |  __/ |   
     |_|\__,_|___/|_| \_\  |_|  |_|\___|_| |_|\___|\__, |\___|_|   
                                                   __/ |           
                                                  |___/            
)";

// ASCII art for MAIN MENU
string mainMenuArt = R"(
 __  __       _         __  __                  
|  \/  |     (_)       |  \/  |                 
| \  / | __ _ _ _ __   | \  / | ___ _ __  _   _ 
| |\/| |/ _` | | '_ \  | |\/| |/ _ \ '_ \| | | |
| |  | | (_| | | | | | | |  | |  __/ | | | |_| |
|_|  |_|\__,_|_|_| |_| |_|  |_|\___|_| |_|\__,_|
)";

// Task structure
struct Task {
    int id;
    string name;
    string createdTime;
    string deadline;
    bool isCompleted;
    bool isCancelled;

    Task(int id, const string& name, const string& deadline)
        : id(id), name(name), isCompleted(false), isCancelled(false) {
        time_t now = time(0);
        createdTime = string(ctime(&now)).substr(0, 24); // Format creation time
        this->deadline = deadline;
    }
};

// TaskManager class
class TaskManager {
private:
    list<Task> tasks;
    unordered_map<int, list<Task>::iterator> taskMap;
    int nextId;

public:
    TaskManager() : nextId(1) {}

    void addTask(const string& taskName, const string& deadline) {
        tasks.emplace_back(nextId, taskName, deadline);
        taskMap[nextId] = --tasks.end();
        cout << "Task added successfully!" << endl;
        ++nextId;
    }

    void displayTasks() const {
        if (tasks.empty()) {
            cout << "\nNo tasks available.\n" << endl;
        } else {
            cout << "\nID   Name                        Created Time           Deadline       Status\n";
            cout << "-----------------------------------------------------------------------------\n";
            for (const auto& task : tasks) {
                cout << setw(4) << task.id << "  " << setw(25) << task.name << "  "
                     << setw(20) << task.createdTime << "  " << setw(10) << task.deadline << "  "
                     << (task.isCompleted ? "Completed" : (task.isCancelled ? "Cancelled" : "Pending"))
                     << endl;
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
            tasks.erase(it->second);
            taskMap.erase(it);
            cout << "Task deleted successfully!" << endl;
        } else {
            cout << "Task not found!" << endl;
        }
    }

    void saveToFile(const string& filename) {
        ofstream outFile(filename);
        if (outFile.is_open()) {
            for (const auto& task : tasks) {
                outFile << task.id << "|" << task.name << "|" << task.createdTime << "|" << task.deadline << "|"
                        << (task.isCompleted ? "1" : "0") << "|" << (task.isCancelled ? "1" : "0") << endl;
            }
            cout << "Tasks saved to " << filename << " successfully!" << endl;
        } else {
            cout << "Unable to save tasks to file." << endl;
        }
    }

    void loadFromFile(const string& filename) {
        ifstream inFile(filename);
        if (inFile.is_open()) {
            tasks.clear();
            taskMap.clear();
            nextId = 1;

            string line;
            while (getline(inFile, line)) {
                string name, createdTime, deadline;
                int id, completed, cancelled;
                size_t pos = 0;

                pos = line.find("|");
                id = stoi(line.substr(0, pos));
                line = line.substr(pos + 1);

                pos = line.find("|");
                name = line.substr(0, pos);
                line = line.substr(pos + 1);

                pos = line.find("|");
                createdTime = line.substr(0, pos);
                line = line.substr(pos + 1);

                pos = line.find("|");
                deadline = line.substr(0, pos);
                line = line.substr(pos + 1);

                pos = line.find("|");
                completed = stoi(line.substr(0, pos));
                line = line.substr(pos + 1);

                cancelled = stoi(line);

                Task task(id, name, deadline);
                task.createdTime = createdTime;
                task.isCompleted = completed;
                task.isCancelled = cancelled;

                tasks.push_back(task);
                taskMap[id] = --tasks.end();
                nextId = max(nextId, id + 1);
            }
            inFile.close();
            cout << "Tasks loaded successfully!" << endl;
        } else {
            cout << "No existing tasks found for this user." << endl;
        }
    }
};

// User class
class User {
private:
    string username;
    string password;

    string getHiddenInput() {
        string input;
        char ch;
        while ((ch = getch()) != '\r') { // '\r' detects Enter key
            if (ch == '\b' && !input.empty()) { // '\b' detects Backspace
                cout << "\b \b"; // Erase the last character
                input.pop_back();
            } else if (ch != '\b') {
                cout << '*';
                input += ch;
            }
        }
        cout << endl;
        return input;
    }

public:
    bool login() {
        displayAsciiArt(taskManagerArt);
        cout << "Enter your username: ";
        cin >> username;
        cout << "Enter your password: ";
        password = getHiddenInput();
        ifstream file(username + ".txt");
        if (file) {
            string storedPassword;
            file >> storedPassword;
            if (storedPassword == password) {
                cout << "Login successful! Welcome back!" << endl;
                return true;
            }
        }
        cout << "Invalid username or password. Please try again." << endl;
        return false;
    }

    bool registerUser() {
        displayAsciiArt(taskManagerArt);
        cout << "Enter a new username: ";
        cin >> username;
        cout << "Enter a new password: ";
        password = getHiddenInput();
        ofstream file(username + ".txt");
        if (file) {
            file << password;
            cout << "Registration successful! You can now log in." << endl;
            return true;
        }
        cout << "Error during registration. Please try again." << endl;
        return false;
    }

    string getTaskFilename() const {
        return username + "_tasks.txt";
    }
};

// Main function
int main() {
    User user;
    TaskManager taskManager;

    bool loggedIn = false;
    while (!loggedIn) {
        displayAsciiArt(welcomeArt);
        cout << "\nChoose an option below:\n\n";
        cout << "1. LOGIN\n";
        cout << "2. REGISTER\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        if (choice == 1) {
            loggedIn = user.login();
        } else if (choice == 2) {
            loggedIn = user.registerUser();
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    string filename = user.getTaskFilename();
    taskManager.loadFromFile(filename);

    int choice;
    while (true) {
        displayAsciiArt(mainMenuArt);
        cout << "1. Add a New Task\n";
        cout << "2. View All Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Cancel a Task\n";
        cout << "5. Delete a Task\n";
        cout << "6. Save Tasks to File\n";
        cout << "7. Logout\n";
        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice == 1) {
            displayAsciiArt(taskManagerArt);
            string taskName, deadline;
            cout << "Enter the task name: ";
            cin.ignore();
            getline(cin, taskName);
            cout << "Enter the deadline (e.g., 2024-12-31): ";
            getline(cin, deadline);
            taskManager.addTask(taskName, deadline);
        } else if (choice == 2) {
            taskManager.displayTasks();
        } else if (choice == 3) {
            displayAsciiArt(taskManagerArt);
            int id;
            cout << "Enter the task ID to mark as completed: ";
            cin >> id;
            taskManager.completeTask(id);
        } else if (choice == 4) {
            displayAsciiArt(taskManagerArt);
            int id;
            cout << "Enter the task ID to cancel: ";
            cin >> id;
            taskManager.cancelTask(id);
        } else if (choice == 5) {
            displayAsciiArt(taskManagerArt);
            int id;
            cout << "Enter the task ID to delete: ";
            cin >> id;
            taskManager.deleteTask(id);
        } else if (choice == 6) {
            displayAsciiArt(taskManagerArt);
            taskManager.saveToFile(filename);
        } else if (choice == 7) {
            displayAsciiArt(taskManagerArt);
            taskManager.saveToFile(filename);
            cout << "Goodbye! See you next time." << endl;
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
