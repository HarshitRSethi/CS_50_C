#include "cs50.h"
#include <stdio.h>

int main(void)
{
    // Ask for height
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1);

    // Actual Pyramid
    // Parent Loop
    for (int i = 1; i < height + 1; i++)
    {
        // Loop for creating spaces
        for (int j = height; j > i; j--)
        {
            printf(" ");
        }
        // Loop for creating column
        for (int k = 0; k < i; k++)
        {
            printf("#");
        }
        // Creating row
        printf("\n");
    }
}
