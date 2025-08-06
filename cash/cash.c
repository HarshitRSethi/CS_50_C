#include "cs50.h"
#include <stdio.h>

int main(void)
{
    // Maybe I can make use of division and int per say
    //  Like say I want to cash 55 right, starting from heaviest, dividing by 25, and taking int
    //  give 2 Now dividing the remainder (5) by 10 give int as 0 Now by 5 give 1
    // by 1 give 0 as remainder became 0.
    //  So total coin used were sum, 2 + 1

    // Prompt for "Change owed"
    int change;
    do
    {
        change = get_int("Change owed: ");
    }
    while (change < 1);

    // Checking usability of quarters in this case by dividing change by 25
    int quarters;
    quarters = change / 25;
    int remaining_change_1 = change % 25;

    // Checking usability of dimes in this case by dividing remainder of previous operation by it
    int dimes;
    dimes = remaining_change_1 / 10;
    int remaining_change_2 = remaining_change_1 % 10;

    // Checking usability of nickels in this case by applying similar to previous procedure
    int nickels;
    nickels = remaining_change_2 / 5;
    int remaining_change_3 = remaining_change_2 % 5;

    // Checking usability of quarters in this case by applying similar to previous procedure
    int pennies;
    pennies = remaining_change_3;
    // Output
    int total = quarters + nickels + dimes + pennies;
    printf("%i\n", total);
}
