#include <string>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

class Employee;
class Pet;

enum Task_type
{
    GROOM,
    ADVERTISE,
    TAKE_CARE
};

string enum_to_string(Task_type task)
{
    switch(task)
    {
        case GROOM: return "GROOM";
        case ADVERTISE: return "ADVERTISE";
        case TAKE_CARE: return "TAKE_CARE";
    }
    return "";
}

class Task
{
public:
    Employee* employee;
    Pet* pet;
    Task_type task_type;
    time_t start_time;
    int work_hours;

    Task(Employee* employee,
         Pet* pet,
         Task_type task_type,
         int work_hours,
         time_t start_time)
    {
        this->employee = employee;
        this->pet = pet;
        this->task_type = task_type;
        this->work_hours = work_hours;
        this->start_time = start_time;
    }
};

void print_tasks_table(vector<Task*> tasks)
{
    cout << "Employee | Pet | Work | Work hours | Start time" << endl;
    cout << "-----------------------------------------------" << endl;

    for(Task* task : tasks)
    {
        cout << task->employee << " | "
             << task->pet << " | "
             << enum_to_string(task->task_type) << " | "
             << task->work_hours << " | "
             << ctime(&task->start_time);
    }
}
