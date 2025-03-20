#include <iostream>
#include <vector>

using namespace std;

struct Task {
    string title;
    string description;
    string dueDate;
    int priority;
    bool completed;

    Task(string t, string d, string date, int p) 
    : title(t), description(d), dueDate(date), priority(p), completed(false){}
};


void addTask(vector<Task> & tasks){
    string title, description, due;
    int prio;

    cout << "Enter task title" << endl;
    getline(cin,title);

    cout << "Enter task desciption" << endl;
    getline(cin,description);

    cout << "Enter due date of taks in format: DD-MM-YYyY" << endl;
    getline(cin,due);

    cout << "Enter priority level 1-5" << endl;
    cin >> prio;
    cin.ignore();

    tasks.push_back(Task(title,description,due,prio));

    cout << "Task added succesfully" << endl;
}

void viewTask(const vector<Task> tasks){
    if(tasks.empty()){
        cout << "No tasks available" << endl;
        return;
    }

    cout << "\n==== Your Tasks ====\n" << endl;

    for(size_t i = 0; i < tasks.size(); i++){
        cout << i + 1 << ". " << tasks[i].title << " (Due: " << tasks[i].dueDate << ")" << endl;
        cout << "   Priority: " << tasks[i].priority << endl;
        cout << "   Description: " << tasks[i].description << endl;
        cout << "   Status: " << (tasks[i].completed ? "Completed" : "Pending") << endl;
        cout << "------------------------" << endl;
    }
}

void removeTask(vector<Task> & tasks){
    if(tasks.empty()){
        cout << "No tasks available" << endl;
        return;
    }

    viewTask(tasks);

    int taskNum;
    cout << "Enter number of task to delete" << endl;
    cin >> taskNum;
    cin.ignore();

    if(taskNum >= 1 && taskNum <= (int)(tasks.size())){
        tasks.erase(tasks.begin() + (taskNum) -1);
        cout << "Task " << taskNum << tasks[taskNum].title << " deleted succesfully" << endl;
    }
    else {
        cout << "Invalid task number" << endl;
    }


}

void completedTask(vector<Task> & tasks){
    if(tasks.empty()){
        cout << "No tasks available" << endl;
        return;
    }

    viewTask(tasks);

    int taskNum;
    cout << "Enter number of task to delete" << endl;
    cin >> taskNum;
    cin.ignore();

    if(taskNum >= 1 && taskNum <= (int)(tasks.size())){
        tasks[taskNum -1].completed = true;
        cout << "Task "<< taskNum << tasks[taskNum].title << " marked completed!" << endl;
    }
    else {
        cout << "Invalid task number" << endl;
    }

}
void taskMenu(){
    cout << "\n==== Task tracker menu =====" << endl;
    cout << "1. Add new task" << endl;
    cout << "2. View tasks" << endl;
    cout << "3. Mark task as completed" << endl;
    cout << "4. Delete task" << endl;
    cout << "5. Exit the programm" << endl;
    cout << "Enter your choice 1-5" << endl;
}

int main(){

    vector<Task> taskList;
    int choice = 0;

    cout << "Task tracker beta" << endl;

    while(choice != 5){
        taskMenu();
        cin >> choice;
        cin.ignore();

        switch(choice){

            case 1:
                addTask(taskList);
            break;

            case 2:
                viewTask(taskList);
            break;

            case 3:
                completedTask(taskList);
            break;

            case 4:
                removeTask(taskList);
            break;

            case 5:
                cout << "Exiting bye!" << endl;
            break;

            default: 
                cout << "Invalid choice, try again" << endl;
        }
    }
    return 0;
}