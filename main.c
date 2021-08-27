#include <stdio.h>

#define SIZE 100000

int identical_right(int snow1[], int snow2[], int start) {
    for(int i = 0; i < 6; i++) {
        if(snow1[i] != snow2[(i + start) % 6]) {
            return 0;
        }
    }

    return 1;
}

int identical_left(int snow1[], int snow2[], int start) {
    int snow2_index = 0;
    for(int i = 0; i < 6; i++) {
        snow2_index = start - i;
        // start: 3
        // i: 0 = 3
        // i: 1 = 2
        // i: 2 = 1
        // i: 3 = 0
        // i: 4 = -1
        // i: 5 = -2
        if(snow2_index < 0) {
            snow2_index = snow2_index + 6;
        }
        if(snow1[i] != snow2[snow2_index]) {
            return 0;
        }
    }
    return 1;
}

int are_identical(int snow1[], int snow2[]) {
    int start;
    for(start = 0; start < 6; start++) {
        if(identical_right(snow1, snow2, start))
            return 1;
        if(identical_left(snow1, snow2, start))
            return 1;
    }
    return 0;
}

void identify_identical(int snowflakes[][6], int n) {
    int i, j;
    for(i = 0; i < n; i++) {
        for(j = i+1; j < n; j++) {
            if(are_identical(snowflakes[i], snowflakes[j])) {
                printf("Twin snowflakes found.\n");
                return;
            }
        }
    }
        printf("No two snowflakes are alike.\n");
}
    /*
       void identical_unused(int values[][6], int n) {
       for(int i = 0; i < n; i++) {
       for(int j = i+1; j < n; j++) {
       for(int k = 0; k < 6; k++) {
       if(values[i][k])

       }
       }
       }
       }
       */

    int main() {
        static int snowflakes[SIZE][6];
        int n, i, j;
        scanf("%d", &n);
        for(i = 0; i < n; i++)
            for(j = 0; j < 6; j++)
                scanf("%d", &snowflakes[i][j]);
        identify_identical(snowflakes, n);

        /*
           int values[10][6] = {5,2,1,4,8,9,
           1,2,3,4,5,6,
           4,5,6,1,2,3,
           1,3,3,4,5,6,
           1,3,4,5,6,6,
           1,3,4,4,5,6,
           6,5,4,3,3,3,
           6,5,4,3,2,2,
           2,2,2,2,2,2,
           1,1,1,1,1,1};
           printf("%d\n", are_identical(values[2], values[0]));
           */
        return 0;
    }
