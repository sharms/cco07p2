#include <stdio.h>

void identify_identical(int values[], int n) {
    int i, j;
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(values[i] == values[j]) {
                printf("Twin integers found.\n");
                return;
            }
        }
    }

    printf("No two integers alike");
}

int identical_right(int snow1[], int snow2[], int start) {
    for(int i = 0; i < 6; i++) {
        if (snow1[i] != snow2[(i + start) % 6]) {
            return 0;
        }
    }
    return 1;
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
    printf("%d\n", identical_right(values[2], values[1], 3));
    return 0;
}
