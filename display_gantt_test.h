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

char* TASKS[] = { "FindBank", "GetMortgage", "DrawDown", "BuildFoundation", "BuildWalls",
                  "RoofAndCeiling", "Plumbing", "Electrics", "InspectBuild", "Snagging"}; //Example tasks array

void display_gantt_test(struct Task *task) {
    struct Task test_data[] = {
            {.name = "", .start_month = 1, .end_month = 2, .num_dependencies = 0, .dependencies = 0},
            {.name = "", .start_month = 2, .end_month = 2, .num_dependencies = 1, .dependencies = {0, 1}},
            {.name = "", .start_month = 4, .end_month = 6, .num_dependencies = 2, .dependencies = {0, 1, 2}},
            {.name = "", .start_month = 3, .end_month = 4, .num_dependencies = 1, .dependencies = {0, 3}},
            {.name = "", .start_month = 4, .end_month = 5, .num_dependencies = 0, .dependencies = 0},
            {.name = "", .start_month = 5, .end_month = 6, .num_dependencies = 2, .dependencies = {0, 4, 5}},
            {.name = "", .start_month = 7, .end_month = 7, .num_dependencies = 1, .dependencies = {0, 6}},
            {.name = "", .start_month = 8, .end_month = 9, .num_dependencies = 1, .dependencies = {0, 7}},
            {.name = "", .start_month = 9, .end_month = 10, .num_dependencies = 1, .dependencies = {0, 5}},
            {.name = "", .start_month = 9, .end_month = 10, .num_dependencies = 9, .dependencies = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}},
    };

    for (int i = 0; i < (sizeof(test_data) / sizeof(test_data[0])); i++) {
        strcpy(test_data[i].name, TASKS[i]);
    }

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

    for (int i = 0; i < sizeof(test_data) / sizeof(test_data[0]); i++) { //loop to print tasks
        int start = test_data[i].start_month - 1; //making value match with enum range (0-11)
        int end = test_data[i].end_month - 1;
        printf("%s", test_data[i].name);

        for (int j = 0; j < (45 - strlen(test_data[i].name)); j++){ //max task name length + printing uniform padding
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

        for (int j = 1; j <= test_data[i].num_dependencies; j++) { //print dependencies (j = 1 so dependency number correlates
            printf(" %d", test_data[i].dependencies[j]); //to task number (1-10)
        }

        for (int j = 0; j < (19 - (test_data[i].num_dependencies * 2)); j++) { //print whitespace for leftover space
            printf(" ");
        }

        printf("\n");
        for (int i = 0; i < 209; i++) { //line border
            printf("-");
        }
        printf("\n");
    }
}
