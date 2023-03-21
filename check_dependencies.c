#include <stdio.h>
#include <stdlib.h>
#define NAME_LEN 44

struct Task {
    char name[NAME_LEN];
    int start_month;
    int end_month;
    int num_dependencies;
    int dependencies[9];
};

int * circular_path(struct Task tasks[], struct Task next_dependency, int task_checked, int *path_length);
void test(struct Task tasks[], int num_tasks);


void test(struct Task tasks[], int num_tasks)
{
    //pointers holding the location of the path length and numbers
    int *ptr_path_length;
    int *ptr_path;
    //variable that indicates whether a path to a circular dependency exists.
    int path_found = 0;

    for(int i = 0; i < num_tasks; i++)
    {
    *ptr_path_length = 0;
    //the function return null if no circular dependency is found,
    //and the path if it is found. I, that case, it also modifies the path length accordingly.
    ptr_path = circular_path(tasks, tasks[i], i, ptr_path_length);
        //printing the path
        if(ptr_path != NULL)
        {
            printf("Circular dependency found!\n"
                    "%d -> ", i);
            for(int j = 0; j < (*ptr_path_length) - 1; j++)
            {
                printf("%d -> ", *(ptr_path + j));
            }
            printf("%d !\n", *(ptr_path + *ptr_path_length));
            path_found = 1;
        }
    }
    if(path_found == 0)
    {
        printf("No circular dependency found.\n");
    }
    printf("End of test.\n");
}


int * circular_path(struct Task tasks[], struct Task next_dependency, int task_checked, int *path_length)
{
    //base case 1: there are no more dependencies to be checked: no path
    if(next_dependency.num_dependencies == 0)
    {
        return NULL;
    }

    //base case 2: the next dependency is the same as the task being checked: path = that dependency
    for(int i = 0; i < next_dependency.num_dependencies; i++)
    {
        if(next_dependency.dependencies[i] == task_checked)
        {
            //use of malloc so that the pointer can be accessed outside this function call
            ++*path_length;
            int *ptr_dependency = malloc(sizeof(int));
            ptr_dependency = &next_dependency.dependencies[i];
            return ptr_dependency;
        }
    }

    //recursive case 1: the path is not null: return the path
    for(int i = 0; i < next_dependency.num_dependencies; i++)
    {
        if(circular_path(tasks, tasks[next_dependency.dependencies[i]], task_checked, path_length) != NULL)
        {
            //same as base case 2 but the function is called again for the remaining of the path
            ++*path_length;
            int *ptr_dependency = malloc(sizeof(int));
            ptr_dependency = &next_dependency.dependencies[i];
            *(ptr_dependency + 1) = *circular_path(tasks, tasks[next_dependency.dependencies[i]], task_checked, path_length);
            return ptr_dependency;
        }
    }

    //recursive case 2: the path is null: no path
    return NULL;
}