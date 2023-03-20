#include <stdio.h>
#include "inputTasks.h"

void test(struct Task tasks[], int num_tasks);
int check_dependencies(struct Task tasks[], struct Task task, int task_index);

/*This method examines the task dependencies recursively and prints whether there is a circular dependency or not.
 * */
void test(struct Task tasks[], int num_tasks)
{
    for(int i = 0; i < num_tasks; i++)
    {
        if(check_dependencies(tasks, tasks[i], i) == 1)
        {
            printf("Warning! Circular dependency found involving '%s'!\n", tasks[i].name);
            break;
        }
        else
        {
            printf("Task %d clear.\n", i+1);
        }
    }
}

int check_dependencies(struct Task tasks[], struct Task task, int task_index)
{
    for(int i = 0; i < task.num_dependencies; i++)
    {
        //base case 2: the task's dependency is the same as the task being checked'
        //recursive case: compare the task index at hand with the dependencies of its dependencies
        if(task.dependencies[i] == task_index || check_dependencies(tasks, tasks[task.dependencies[i]], task_index) == 1)
        {
            return 1;
        }
    }

    //base case 1: there is no dependency to check
    return 0;
}
