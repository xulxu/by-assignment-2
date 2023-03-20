#include <stdio.h>
#include "inputTasks.h"
#include "display_gantt_test.h"

int main() {
    int user_choice;

    userchoice:
    printf("Welcome to the Gantt Generator.\n"
           "Would you like to view a test example or create your Gantt Chart from scratch? (1 or 2)\n");
    scanf("%d", &user_choice);

    if (user_choice == 1) {
        display_gantt_test();
    } else if (user_choice == 2) {
        struct Task user_task[10];
        struct Task *ptr_task;
        int num_tasks;
        int choice;

        printf("How many tasks do you wish to add? (1-10)\n");
        scanf("%d", &num_tasks);

        while(num_tasks < 1) {
            printf("You must enter at least one task.\n");
            scanf("%d", &num_tasks);
        }

        while(num_tasks > 10) {
            printf("That is too many tasks. Please add at most 10 tasks.\n");
            scanf("%d", &num_tasks);
        }

        for(int i = 0; i < num_tasks; i++) {
            ptr_task = &user_task[i];
            input_task(ptr_task, num_tasks, i);
        }
        printf("\n");
        gantt_static();

        for(int i = 0; i < num_tasks; i++) {
            display_gantt(user_task[i], i);
        }

        while(1) {
            printf("Type '1' to edit a task and '2' to exit the program.\n");
            scanf("%d", &choice);

            while(choice < 1 || choice > 2) {
                printf("Please enter a number between 1 and 2.\n");
                scanf("%d", &choice);
            }

            if(choice == 1) {
                edit(user_task, num_tasks);
            } else {
                return 0;
            }
        }
    } else {
        printf("That is an invalid input. Please try again.\n");
        goto userchoice;
    }
}

