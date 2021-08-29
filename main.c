#include <stdio.h>
#include <stdlib.h>

#define SIZE 100000

typedef struct snowflake_node
{
    int snowflake[6];
    struct snowflake_node *next;
} snowflake_node;

int identical_right(int snow1[], int snow2[], int start)
{
    for (int i = 0; i < 6; i++)
    {
        if (snow1[i] != snow2[(i + start) % 6])
        {
            return 0;
        }
    }

    return 1;
}

int identical_left(int snow1[], int snow2[], int start)
{
    int snow2_index = 0;
    for (int i = 0; i < 6; i++)
    {
        snow2_index = start - i;
        // start: 3
        // i: 0 = 3
        // i: 1 = 2
        // i: 2 = 1
        // i: 3 = 0
        // i: 4 = -1
        // i: 5 = -2
        if (snow2_index < 0)
        {
            snow2_index = snow2_index + 6;
        }
        if (snow1[i] != snow2[snow2_index])
        {
            return 0;
        }
    }
    return 1;
}

int are_identical(int snow1[], int snow2[])
{
    int start;
    for (start = 0; start < 6; start++)
    {
        if (identical_right(snow1, snow2, start))
            return 1;
        if (identical_left(snow1, snow2, start))
            return 1;
    }
    return 0;
}

void identify_identical(snowflake_node *snowflakes[])
{
    snowflake_node *node1, *node2;
    int i;
    for (i = 0; i < SIZE; i++)
    {
        node1 = snowflakes[i];
        while (node1 != NULL)
        {
            node2 = node1->next;
            while (node2 != NULL)
            {
                if (are_identical(node1->snowflake, node2->snowflake))
                {
                    printf("Twin snowflakes found.\n");
                    return;
                }

                node2 = node2->next;
            }
        }
    }
    printf("No two snowflakes are alike.\n");
}

int code(int snowflake[])
{
    return (snowflake[0] + snowflake[1] + snowflake[2] + snowflake[3] + snowflake[4] + snowflake[5]) % SIZE;
}

int main()
{
    static snowflake_node *snowflakes[SIZE] = {NULL};
    snowflake_node *snow;
    int n, i, j, snowflake_code;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        snow = malloc(sizeof(snowflake_node));
        if (snow == NULL)
        {
            fprintf(stderr, "malloc error\n");
            exit(1);
        }
        for (j = 0; j < 6; j++)
            scanf("%d", &snow->snowflake[j]);
        snowflake_code = code(snow->snowflake);
        snow->next = snowflakes[snowflake_code];
        snowflakes[snowflake_code] = snow;
    }
    identify_identical(snowflakes);

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
