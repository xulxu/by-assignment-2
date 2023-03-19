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

void display_gantt_test() {
    for (int i = 0; i < 204; i++){ //top border
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

                for (int k = 0; k < right_padding; k++) { //right padding
                    printf(" ");
                }

                printf("|");
                }

            printf("  Dependencies");
        }
    }
    printf("\n");

    for (int i = 0; i < 204; i++){ //line borders
        printf("-");
    }

    printf("\n");

    char* TASKS[] = { "FindBank", "GetMortgage", "DrawDown", "BuildFoundation", "BuildWalls",
    "RoofAndCeiling", "Plumbing", "Electrics", "Inspect_Build", "Snagging"}; //Tasks array

    for (int i = 0; i < sizeof(TASKS) / sizeof(TASKS[0]); i++) { //loop to print tasks
        printf("%s", TASKS[i]);

        for (int j = 0; j < (45 - strlen(TASKS[i])); j++){ //max task name length + printing uniform padding
            printf(" ");
        }

        for (int k = 0; k < 13; k++) { //month cells
            printf("|");
            for (int i = 0; i < 11; i++){
                printf(" ");
            }
        }

        printf("\n");
        for (int i = 0; i < 204; i++){ //line border
            printf("-");
        }
        printf("\n");
    }
}
