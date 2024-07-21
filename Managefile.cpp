#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;
};

void displayMenu() {
    cout << "To-Do List Manager" << endl;
    cout << "1. Add a task" << endl;
    cout << "2. Display tasks" << endl;
    cout << "3. Mark task as completed" << endl;
    cout << "4. Remove a task" << endl;
    cout << "5. Exit" << endl;
    cout << "Choose an option: ";
}

void addTask(vector<Task>& tasks) {
    Task newTask;
    cout << "Enter the description of the task: ";
    cin.ignore();
    getline(cin, newTask.description);
    newTask.completed = false;
    tasks.push_back(newTask);
    cout << "Task added!" << endl;
}

void displayTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks to display." << endl;
        return;
    }

    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i].description;
        if (tasks[i].completed) {
            cout << " [Completed]";
        }
        cout << endl;
    }
}

void markTaskAsCompleted(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks to mark as completed." << endl;
        return;
    }

    int taskNumber;
    cout << "Enter the number of the task to mark as completed: ";
    cin >> taskNumber;

    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        tasks[taskNumber - 1].completed = true;
        cout << "Task marked as completed!" << endl;
    } else {
        cout << "Invalid task number." << endl;
    }
}

void removeTask(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks to remove." << endl;
        return;
    }

    int taskNumber;
    cout << "Enter the number of the task to remove: ";
    cin >> taskNumber;

    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        tasks.erase(tasks.begin() + taskNumber - 1);
        cout << "Task removed!" << endl;
    } else {
        cout << "Invalid task number." << endl;
    }
}

int main() {
    vector<Task> tasks;
    int option;

    do {
        displayMenu();
        cin >> option;

        switch (option) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                displayTasks(tasks);
                break;
            case 3:
                markTaskAsCompleted(tasks);
                break;
            case 4:
                removeTask(tasks);
                break;
            case 5:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
                break;
        }

        cout << endl;

    } while (option != 5);

    return 0;
}
