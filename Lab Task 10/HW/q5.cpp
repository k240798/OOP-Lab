#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class TodoList {
private:
    std::string filename;

    void loadTasks(std::vector<std::string>& tasks) {
        std::ifstream file(filename);
        std::string task;
        while (std::getline(file, task)) {
            tasks.push_back(task);
        }
    }

    void saveTasks(const std::vector<std::string>& tasks) {
        std::ofstream file(filename, std::ios::trunc);
        for (const auto& task : tasks) {
            file << task << std::endl;
        }
    }

public:
    TodoList(std::string file) : filename(file) {}

    void addTask(const std::string& task) {
        std::vector<std::string> tasks;
        loadTasks(tasks);
        tasks.push_back(task);
        saveTasks(tasks);
    }

    void viewTasks() {
        std::vector<std::string> tasks;
        loadTasks(tasks);
        std::cout << "To-Do List:" << std::endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << (i + 1) << ". " << tasks[i] << std::endl;
        }
    }

    void markTaskDone(int taskIndex) {
        std::vector<std::string> tasks;
        loadTasks(tasks);

        if (taskIndex < 1 || taskIndex > tasks.size()) {
            std::cerr << "Invalid task index!" << std::endl;
            return;
        }

        tasks[taskIndex - 1] += " [Done]";
        saveTasks(tasks);
    }
};

int main() {
    TodoList todo("tasks.txt");

    while (true) {
        std::cout << "1. Add Task" << std::endl;
        std::cout << "2. View Tasks" << std::endl;
        std::cout << "3. Mark Task as Done" << std::endl;
        std::cout << "4. Exit" << std::endl;
        int choice;
        std::cin >> choice;
        std::cin.ignore(); 

        if (choice == 1) {
            std::cout << "Enter task description: ";
            std::string task;
            std::getline(std::cin, task);
            todo.addTask(task);
        } else if (choice == 2) {
            todo.viewTasks();
        } else if (choice == 3) {
            std::cout << "Enter task number to mark as done: ";
            int taskIndex;
            std::cin >> taskIndex;
            todo.markTaskDone(taskIndex);
        } else if (choice == 4) {
            break;
        } else {
            std::cerr << "Invalid choice!" << std::endl;
        }
    }

    return 0;
}
