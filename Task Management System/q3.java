import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;
class Task {
	String description;
	boolean completed;

	Task(String description, boolean completed) {
		this.description = description;
		this.completed = completed;
	}
}

class TaskManager {
	static void displayTasks(ArrayList<Task> tasks) {
		System.out.println("Task List:");
		for (int i = 0; i < tasks.size(); ++i) {
			System.out.print("[" + (i + 1) + "] ");
			System.out.print(tasks.get(i).completed ? "[Completed] " : "[Pending] ");
			System.out.println(tasks.get(i).description);
		}
	}
	static void addTask(ArrayList<Task> tasks, String description) {
		Task newTask = new Task(description, false);
		tasks.add(newTask);
	}
	static void editTask(ArrayList<Task> tasks, int taskIndex, String newDescription) {
		if (taskIndex >= 0 && taskIndex < tasks.size()) {
			tasks.get(taskIndex).description = newDescription;
		} else {
			System.out.println("Invalid task index.");
		}
	}
	static void completeTask(ArrayList<Task> tasks, int taskIndex) {
		if (taskIndex >= 0 && taskIndex < tasks.size()) {
			tasks.get(taskIndex).completed = true;
		} else {
			System.out.println("Invalid task index.");
		}
	}
	static void saveTasks(ArrayList<Task> tasks, String filename) {
		try (PrintWriter writer = new PrintWriter(filename)) {
			for (Task task : tasks) {
				writer.println(task.completed + " " + task.description);
			}
		} catch (FileNotFoundException e) {
			System.out.println("Error: Unable to save tasks to file.");
		}
	}
	static void deleteTask(ArrayList<Task> tasks,int taskIndex) {
		if (taskIndex >= 0 && taskIndex < tasks.size()) {
			tasks.remove(taskIndex);
		} else {
			System.out.println("Invalid task index");
		}
	}
	static void loadTasks(ArrayList<Task> tasks, String filename) {
		try (Scanner scanner = new Scanner(new File(filename))) {
			tasks.clear();
			while (scanner.hasNextLine()) {
				String[] parts = scanner.nextLine().split(" ", 2);
				boolean completed = Boolean.parseBoolean(parts[0]);
				String description = parts[1];
				tasks.add(new Task(description, completed));
			}
		} catch (FileNotFoundException e) {
			System.out.println("Error: Unable to load tasks from file.");
		}
	}

	public static void main(String[] args) {
		ArrayList<Task> tasks = new ArrayList<>();
		String filename = "task_history.txt";
		loadTasks(tasks, filename);

		Scanner scanner = new Scanner(System.in);

		while (true) {
			System.out.println("\nOptions:");
			System.out.println("1. Display Tasks");
			System.out.println("2. Add Task");
			System.out.println("3. Edit Task");
			System.out.println("4. Complete Task");
			System.out.println("5. Save and Quit");
			System.out.println("6. Delete Task");

			System.out.print("Enter your choice: ");
			int choice = scanner.nextInt();

			switch (choice) {
				case 1:
					displayTasks(tasks);
					break;
				case 2:
					scanner.nextLine();
					System.out.print("Enter task description: ");
					String description = scanner.nextLine();
					addTask(tasks, description);
					break;
				case 3:
					System.out.print("Enter task index to edit: ");
					int taskIndexEdit = scanner.nextInt() - 1;
					scanner.nextLine();
					System.out.print("Enter new task description: ");
					String newDescription = scanner.nextLine();
					editTask(tasks, taskIndexEdit, newDescription);
					break;
				case 4:
					System.out.print("Enter task index to mark as completed: ");
					int taskIndexComplete = scanner.nextInt() - 1;
					completeTask(tasks, taskIndexComplete);
					break;
				case 5:
					saveTasks(tasks, filename);
					scanner.close();
					return;

				case 6:
					System.out.print("Enter task index to delete . ");
					int taskIndexDelete = scanner.nextInt() - 1;
					deleteTask( tasks,taskIndexDelete);
				default:
					System.out.println("Invalid choice. Please try again.");
			}
		}
	}
}
