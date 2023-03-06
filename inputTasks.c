#include <stdio.h>
#include "main.c"
#define NAME_LEN 30

void input_task(struct task Task, int num_tasks);
void edit(struct task Tasks[], int num_tasks);
void print_task(struct task Task);

void input_task(struct task Task, int num_tasks)
{
    //taks name
    printf("Please enter a name for the task:\n")
    fgets(Task.name, NAME_LEN, stdin);
    
    //tast starting month
    printf("Please enter a starting month (1-12):\n");
    scanf("%d", &Task.start_month);
    while(Task.start_month < 1 || Task.start_month > 12)
    {
        printf("The month should be indicated with a number between 1 and 12. Please enter again:\n");
        scanf("%d", &Task.start_month);
    }

    //task ending month
    printf("Please enter an ending month (1-12):\n");
    scanf("%d", &Task.end_month);
    while(Task.end_month < 1 || Task.end_month > 12 || Task.end_month < Task.start_month)
    {
        if(Task.end_month < Task.start_month)
        {
            printf("The end month cannot happen before the start month. ");
        }
        else
        {
            printf("The month should be indicated with a number between 1 and 12. ");
        }
        printf("Please enter again:\n");
        scanf("%d", &Task.end_month);
    }

    //task dependences
    printf("Please enter the number of dependences:\n")
    scanf("%d", &Task.num_dependences);
    while(Task.num_dependences < 0 || > 9)
    {
        printf("The number of dependences must be comprised between 0 and 9. Please enter again:\n");
        scanf("%d", &Task.num_dependences);
    }
    for(int i = 0; i < Task.num_dependences; i++)
    {
        printf("Dependency %d (number):\n", i+1);
        scanf("%d", & Task.dependences[i]);
        while(Task.num_dependences[i] < 1 || > num_tasks)
        {
            printf("The task number must be comprised between 1 and %d. Please enter again:\n", num_tasks);
            scanf("%d", & Task.dependences[i]);
        }
    }
}


void edit(struct task Tasks[], int num_tasks)
{
    char task_name;
    printf("Please enter the name of the task to modify:\n");
    fgets(task_name, NAME_LEN, stdin);
    for(int i = 0; i < num_tasks; i++){
        if(strcmp(Tasks[i].name, task_name) == 0)
        {
            printf("Previous version of this task:\n")
            print_task(Task[i]);
            input_task(Task[i], num_tasks);
            display_gantt(num_tasks, task Tasks);
        }
    }
}


void print_task(struct task Task)
{
    printf("Task name: %s\n", Task.name);
    printf("Sarting month: %d\n", Task.start_month);
    printf("Ending month: %d\n", Task.start_month);
    printf("Dependencies: ");
    for(int i = 0; i < Task.num_dependences; i++)
    {
        printf("%d ", Task.dependences[i]);
    }
    printf("\n");
}