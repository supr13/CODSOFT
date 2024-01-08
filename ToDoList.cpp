#include <iostream>
#include <vector>
#include <algorithm>

struct Task {
    std::string description;
    bool completed;
};

std::vector<Task> tasks;

void addTask(const std::string& description) {
    Task newTask;
    newTask.description = description;
    newTask.completed = false;
    tasks.push_back(newTask);
}

void viewTasks() {
    std::cout << "Tasks:\n";
    for (const auto& task : tasks) {
        std::cout << "- " << task.description;
        if (task.completed) {
            std::cout << " (completed)";
        } else {
            std::cout << " (pending)";
        }
        std::cout << "\n";
    }
}

void markTaskAsCompleted(int index) {
    if (index >= 0 && index < tasks.size()) {
        tasks[index].completed = true;
    }
}

void removeTask(int index) {
    if (index >= 0 && index < tasks.size()) {
        tasks.erase(tasks.begin() + index);
    }
}

int main() {
    int choice;
    std::string description;

    while (true) {
        std::cout << "To-Do List Manager\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Mark Task as Completed\n";
        std::cout << "4. Remove Task\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter task description: ";
                std::cin.ignore();
                std::getline(std::cin, description);
                addTask(description);
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                int index;
                std::cout << "Enter task index: ";
                std::cin >> index;
                markTaskAsCompleted(index);
                break;
            case 4:
                std::cout << "Enter task index: ";
                std::cin >> index;
                removeTask(index);
                break;
            case 5:
                std::cout << "Thank you for using the To-Do List Manager!\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }

        std::cout << "\n";
    }
}
