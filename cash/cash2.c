#include "cs50.h"
#include <stdio.h>

int calculate_number_of_coins(int change, int number);
int calculate_remaining_change(int change, int number);

#define A_QUARTER 25
#define A_DIME 10
#define A_NICKEL 5

int main(void)
{
    // Prompt for "Change owed"
    int change;
    do
    {
        change = get_int("Change owed: ");
    }
    while (change < 1);

    // Checking usability of quarters in this case
    int quarters = calculate_number_of_coins(change, A_QUARTER);
    int remaining_balance_1 = calculate_remaining_change(change, A_QUARTER);

    // Checking usability of dimes in this case
    int dimes = calculate_number_of_coins(remaining_balance_1, A_DIME);
    int remaining_balance_2 = calculate_remaining_change(remaining_balance_1, A_DIME);

    // Checking usability of quarters in this case
    int nickels = calculate_number_of_coins(remaining_balance_2, A_NICKEL);
    int remaining_balance_3 = calculate_remaining_change(remaining_balance_2, A_NICKEL);

    // Checking usability of quarters in this case
    int pennies = remaining_balance_3;

    // Output
    int total = quarters + dimes + nickels + pennies;
    printf("%i\n", total);
}

int calculate_number_of_coins(int change, int number)
{
    return change / number;
}
int calculate_remaining_change(int change, int number)
{
    return change % number;
}
