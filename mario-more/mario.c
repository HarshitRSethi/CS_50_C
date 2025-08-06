#include "cs50.h"
#include <stdio.h>

int main(void)
{
    // Asking for height
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height > 8 || height < 1);

    // Parent Loop
    for (int i = 1; i < height + 1; i++)
    {
        // Loop for creating spaces
        for (int j = height; j > i; j--)
        {
            printf(" ");
        }
        // Loop for creating first column
        for (int k = 0; k < i; k++)
        {
            printf("#");
        }
        // Constant space
        printf("  ");
        // Loop for creating second column
        for (int l = 0; l < i; l++)
        {
            printf("#");
        }
        // Creating row
        printf("\n");
    }
}
