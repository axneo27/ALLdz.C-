#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Task {
private:
	int id;
	bool isDone;
	string description;
public:
	Task(int id, string description) {
		this->id = id;
		this->description = description;
		this->isDone = false;
	}

	int getId() {
		return id;
	}

	string getDescription() {
		return description;
	}

	bool getIsDone() {
		return isDone;
	}

	void setIsDone(bool isDone) {
		this->isDone = isDone;
	}

	void Show() {
		cout << "__________________________\n";
		cout << "Task #" << id << " " << description << "\n" << (isDone? "DONE" : "NOT DONE") << endl;
		cout << "__________________________\n";
	}
};

class ToDoList {
private:
	vector<Task> tasks = {};
	int tasksCount = 0;

public:
	ToDoList() {
	}
	void AddTask(Task task) {
		tasks.push_back(task);
		tasksCount++;
	}
	void ShowTasks() {
		for (int i = 0; i < tasksCount; i++) {
			tasks[i].Show();
		}
	}
	void SetTaskDone(int id) {
		for (int i = 0; i < tasksCount; i++) {
			if (tasks[i].getId() == id) {
				tasks[i].setIsDone(true);
			}
		}
	}
	void SetTaskNotDone(int id) {
		for (int i = 0; i < tasksCount; i++) {
			if (tasks[i].getId() == id) {
				tasks[i].setIsDone(false);
			}
		}
	}
	void RemoveTask(int id) {
		for (int i = 0; i < tasksCount; i++) {
			if (tasks[i].getId() == id) {
				tasks.erase(tasks.begin() + i);
				tasksCount--;
			}
		}
	}

	void Run() {
		int id = 1;
		while (true) {
			string choice;
			cout << "1. Add task\n2. Show all tasks\n3. Delete a task\n4. Set task done\n5. Exit\n";
			getline(cin, choice);

			string description;
			string id2;

			switch (stoi(choice)) {
			case 1:
				cout << "Enter task description: ";
				getline(cin, description);
				AddTask(Task(id, description));
				id++;
				break;
			case 2:
				ShowTasks();
				break;
			case 3:
				cout << "Enter task id: ";
				getline(cin, id2);
				RemoveTask(stoi(id2));
				break;
			case 4:
				cout << "Enter task id: ";
				getline(cin, id2);
				SetTaskDone(stoi(id2));
				break;
			case 5:
				return;
			default:
				cout << "Invalid choice\n";
				break;
			}
		}
	}

};

int main() {
	ToDoList list;
	list.Run();
	return 0;
}
