#include <stdio.h>
#include <string.h>
#define NAME_LEN 44

struct Task {
    char name[NAME_LEN];
    int start_month;
    int end_month;
    int num_dependencies;
    int dependencies[9];
};

void input_task(struct Task *task, int num_tasks, int task_index);
void edit(struct Task tasks[], int num_tasks);

void input_task(struct Task *task, int num_tasks, int task_index)
{
    //for readability, task index is converted to the task number and not its position in the array
    task_index++;

    //task name
    getchar(); //Clear input buffer. Newline carried over from userchoice in main.c
    printf("Task %d name:\n", task_index);
    fgets(task->name, NAME_LEN, stdin);
    while(task->name[0] == '\n')
    {
        printf("Please enter at least one character for the task name.\n");
        fgets(task->name, NAME_LEN, stdin);
    }
    task->name[strlen(task->name)-1] = '\0';

    //task starting month
    printf("Please enter a starting month (1-12):\n");
    scanf("%d", &task->start_month);
    while(task->start_month < 1 || task->start_month > 12)
    {
        printf("The month should be indicated with a number between 1 and 12. Please enter again:\n");
        scanf("%d", &task->start_month);
    }

    //task ending month
    printf("Please enter an ending month (1-12):\n");
    scanf("%d", &task->end_month);
    while(task->end_month < 1 || task->end_month > 12 || task->end_month < task->start_month)
    {
        if(task->end_month < task->start_month)
        {
            printf("The end month cannot happen before the start month. ");
        }
        else
        {
            printf("The month should be indicated with a number between 1 and 12. ");
        }
        printf("Please enter again:\n");
        scanf("%d", &task->end_month);
    }

    //task number of dependencies
    printf("Please enter the number of dependencies:\n");
    scanf("%d", &task->num_dependencies);
    while(task->num_dependencies <0 || task->num_dependencies > (num_tasks - 1))
    {
        printf("The number of dependencies must be comprised between 0 and %d. Please enter again:\n", num_tasks - 1);
        scanf("%d", &task->num_dependencies);
    }

    //task dependencies
    for(int i = 0; i < task->num_dependencies; i++)
    {
        printf("Dependency %d (please indicate the task number):\n", i+1);
        scanf("%d", &task->dependencies[i]);
        while(task->dependencies[i] < 1 || task->dependencies[i] > num_tasks || task->dependencies[i] == task_index)
        {
            if(task->dependencies[i] < 1 || task->dependencies[i] > num_tasks)
            {
                printf("The task number must be between 1 and %d. ", num_tasks);
            }
            else
            {
                printf("The task cannot be its own dependency! ");
            }
            printf("Please enter again:\n");
            scanf("%d", &task->dependencies[i]);
        }
    }
}


void edit(struct Task tasks[], int num_tasks)
{
    char task_name[NAME_LEN] = {}; //initialize array to 0
    getchar(); //Clear input buffer. Newline carried over from userchoice in main.c
    printf("Please enter the name of the task to modify:\n");
    fgets(task_name, NAME_LEN, stdin);
    task->name[strlen(task->name)-1] = '\0';
    if(task_name[0] != '\n')
    {
        for(int i = 0; i <= num_tasks; i++)
        {
            if(strcmp(tasks[i].name, task_name) == 0) //issue might be newline in task_name because of fgets.
            {
                input_task(&tasks[i], num_tasks, i);
                break;
            }
        }
    }
    else
    {
        printf("Operation cancelled.\n");
    }    
}

