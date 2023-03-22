#include <stdio.h>
#include <string.h>

enum months { //enums as requested by assignment
    January,February,March,April,May,June,
    July,August,September,October,November,December
};

const char *MONTH_NAME[] = { //month array (in pair with enums)
    "January","February","March","April","May","June",
    "July","August","September","October","November","December"
};

struct Task test_data[10] = { //preset for example gantt chart. use of enums
        {.name = "Brainstorm", .start_month = January, .end_month = February, .num_dependencies = 0, .dependencies = 0},
        {.name = "Finalizing Choice", .start_month = February, .end_month = February, .num_dependencies = 1, .dependencies = 1},
        {.name = "Research", .start_month = February, .end_month = March, .num_dependencies = 1, .dependencies = 2},
        {.name = "Design", .start_month = March, .end_month = March, .num_dependencies = 1, .dependencies = 3},
        {.name = "Prototyping", .start_month = April, .end_month = June, .num_dependencies = 2, .dependencies = {3, 4}},
        {.name = "Manufacturing", .start_month = June, .end_month = October, .num_dependencies = 3, .dependencies = {3, 4, 5}},
        {.name = "Construction", .start_month = October, .end_month = October, .num_dependencies = 1, .dependencies = 6},
        {.name = "Finish", .start_month = October, .end_month = November, .num_dependencies = 2, .dependencies = {4, 7}},
        {.name = "Review", .start_month = November, .end_month = December, .num_dependencies = 1, .dependencies = 8},
        {.name = "Evaluation", .start_month = December, .end_month = December, .num_dependencies = 2, .dependencies = {8, 9}},
};

void display_gantt(struct Task task);

void gantt_static() { //function that prints static features of a gantt chart
    for (int i = 0; i < 209; i++){ //top border
        printf("_");
    }

    printf("\n");

    for (int i = 0; i < 45; i++) { //empty cell for task name
        printf(" ");

        if (i == 44) { //start of month printing
            printf("|");

            const int MONTH_SLOT_SIZE = 11; //constant cell width (Longest month name [September} + 2 [padding])

            for (enum months month = January; month <= December; month++) { //print month cells. via loop and use of enums
                int month_length = strlen(MONTH_NAME[month]); //length of month string
                int left_padding = (MONTH_SLOT_SIZE - month_length) / 2; //left padding of month name
                int right_padding = MONTH_SLOT_SIZE - (left_padding + month_length); //right padding of month name

                for (int k = 0; k < left_padding; k++){ //left padding
                    printf(" ");
                }

                printf("%s", MONTH_NAME[month]); //print month

                for (int k = 0; k < right_padding; k++){ //right padding
                    printf(" ");
                }

                printf("|");
            }

            printf("  Dependencies");
        }
    }
    printf("\n");

    for (int i = 0; i < 209; i++){ //line borders
        printf("-");
    }
    printf("\n");
}
void display_gantt(struct Task task) {
     int start = task.start_month;
     int end = task.end_month;

     printf("%s", task.name);

     for (int j = 0; j < (45 - strlen(task.name)); j++){ //max task name length + printing uniform padding
         printf(" ");
     }

     for (enum months month = January; month <= December; month++) { //month cells
         printf("|");
         printf("    ");

         if (month >= start && month <= end){ //print XXX for months between start and end
             printf("XXX    ");
         } else {
             printf("       ");
         }
     }
     printf("|");

     for (int j = 0; j < task.num_dependencies; j++) {
         printf(" %d", task.dependencies[j]);
     }

     for (int j = 0; j < (19 - (task.num_dependencies * 2)); j++) { //print whitespace for leftover space
         printf(" ");
     }

     printf("\n");
     for (int i = 0; i < 209; i++) { //line border
         printf("-");
     }
     printf("\n");
}
