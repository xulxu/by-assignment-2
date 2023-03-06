#include <stdio.h>

enum months {
    January,February,March,April,May,June,
    July,August,September,October,November,December
};

const char *month_name[] = {
    "January","February","March","April","May","June",
    "July","August","September","October","November","December"
};

void display_gantt_test() {
    int i;
    for (i = 0; i < 200; i++){
        printf("_");
    }
    printf("\n");
    for (i = 0; i < 45; i++) {
        printf(" ");
        if (i == 44) {
            printf("|");
            for (enum months month = January; month <= December; month++) {
                printf("  %s  |", month_name[month]);
            }
            printf("  Dependencies");
        }
    }
    printf("\n");
    for (i = 0; i < 200; i++){
        printf("-");
    }
    printf("\n");
}

int main() {
    display_gantt_test();
}
