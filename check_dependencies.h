#include <stdio.h>
#include <stdlib.h>

int circular_path(struct Task tasks[], struct Task next_dependency, int task_checked, int *path_length, int *path);
void test(struct Task tasks[], int num_tasks);


void test(struct Task tasks[], int num_tasks)
{
    //pointers holding the location of the path length and numbers
    int path_length;
    int *ptr_path_length = &path_length;
    int *ptr_path = malloc(sizeof(int) * 10);

    for(int i = 0; i < num_tasks; i++)
    {
        *ptr_path_length = 0;
        if(circular_path(tasks, tasks[i], i+1, ptr_path_length, ptr_path) == 1)
        {
            printf("Circular dependency found!\n");
            printf("%d -> ", i+1);
            for(int j = 0; j < (*ptr_path_length) - 1; j++)
            {
                printf("%d -> ", *(ptr_path + j));
            }
            //pointer path - 1 because count starts at 0
            printf("%d !\n", *(ptr_path - 1 + *ptr_path_length));
            goto end_test;
        }
    }

    printf("No circular dependency found.\n");

    end_test:
    printf("End of test.\n");
    free(ptr_path);
}


int circular_path(struct Task tasks[], struct Task next_dependency, int task_checked, int *path_length, int *path)
{
    //base case 1: there are no more dependencies to be checked: no path
    if(next_dependency.num_dependencies == 0)
    {
        return 0;
    }

    //base case 2: the next dependency is the same as the task being checked: write that dependency
    for(int i = 0; i < next_dependency.num_dependencies; i++)
    {
        if(next_dependency.dependencies[i] == task_checked)
        {
            (*path_length)++;
            *path = next_dependency.dependencies[i];
            return 1;
        }
    }

    //recursive case 1: the path exists: write dependencies along that path
    for(int i = 0; i < next_dependency.num_dependencies; i++)
    {
        if(circular_path(tasks, tasks[next_dependency.dependencies[i]-1], task_checked, path_length, path+1) == 1)
        {
            (*path_length)++;
            *path = next_dependency.dependencies[i];
            return 1;
        }
    }

    //recursive case 2: the path is null: no path
    return 0;
}