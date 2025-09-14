#include <iostream>
#include <vector>
#include <string>

struct Task {
    std::string description;
    bool completed;
};

void addTask(std::vector<Task>& tasks) {
    std::string description;
    std::cout << "Enter the task description: ";
    std::cin.ignore(); 
    std::getline(std::cin, description);
    tasks.push_back({description, false});
    std::cout << "Task added successfully!\n";
}

void viewTasks(const std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks in the list.\n";
        return;
    }
    std::cout << "--- Your To-Do List ---\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << i + 1 << ". ";
        if (tasks[i].completed) {
            std::cout << "[Completed] ";
        } else {
            std::cout << "[Pending] ";
        }
        std::cout << tasks[i].description << "\n";
    }
    std::cout << "-----------------------\n";
}

void markTaskCompleted(std::vector<Task>& tasks) {
    viewTasks(tasks);
    if (tasks.empty()) {
        return;
    }
    int taskNumber;
    std::cout << "Enter the number of the task to mark as completed: ";
    std::cin >> taskNumber;
    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        tasks[taskNumber - 1].completed = true;
        std::cout << "Task " << taskNumber << " marked as completed!\n";
    } else {
        std::cout << "Invalid task number.\n";
    }
}

void removeTask(std::vector<Task>& tasks) {
    viewTasks(tasks);
    if (tasks.empty()) {
        return;
    }
    int taskNumber;
    std::cout << "Enter the number of the task to remove: ";
    std::cin >> taskNumber;
    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        tasks.erase(tasks.begin() + (taskNumber - 1));
        std::cout << "Task removed successfully!\n";
    } else {
        std::cout << "Invalid task number.\n";
    }
}

int main() {
    std::vector<Task> tasks;
    int choice;

    while (true) {
        std::cout << "\n--- To-Do List Manager ---\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Mark Task as Completed\n";
        std::cout << "4. Remove Task\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                markTaskCompleted(tasks);
                break;
            case 4:
                removeTask(tasks);
                break;
            case 5:
                std::cout << "Exiting program. Goodbye!\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}