#include "cs50.h"
#include <stdio.h>

long creator(long number, long digit);
int isolator(long number_remainder_on_, long digit);

int main(void)
{
    // Asking for Credit card number
    long number;
    do
    {
        number = get_long("Number: ");
    }
    while (number < 0 || number > 9999999999999999);
    // Calculating Validity
    // In order to calculate validity I have to seperate different numeric digit from no. like ones,
    // tens etc What I can do to calculate tens place per say is to first get remainder on division
    // by 10 get remainder on division by 100 subtract 4 from it and divide four in it A better way
    // is to use int, let's say no. is 50050245 no in order to isolate hundred digit I can get
    // remainder on division by hundred, save it as int and then created another int which divide
    // remainder by 100 to isolate it. Lets do it Now program would be repeated I think so its
    // better to create a test program first

    // Finding card, if valid
    // Isolating 1 place
    long a = 1;
    long number_remainder_1 = creator(number, a * 10);
    int number_1 = isolator(number_remainder_1, a);

    // Isolating 2 place
    long b = 10;
    long number_remainder_2 = creator(number, b * 10);
    int number_2 = isolator(number_remainder_2, b);

    // Isolating 3 place
    long c = 100;
    long number_remainder_3 = creator(number, c * 10);
    int number_3 = isolator(number_remainder_3, c);

    // Isolating 4 place
    long d = 1000;
    long number_remainder_4 = creator(number, d * 10);
    int number_4 = isolator(number_remainder_4, d);

    // Isolating 5 place
    long e = 10000;
    long number_remainder_5 = creator(number, e * 10);
    int number_5 = isolator(number_remainder_5, e);

    // Isolating 6 place
    long f = 100000;
    long number_remainder_6 = creator(number, f * 10);
    int number_6 = isolator(number_remainder_6, f);

    // Isolating 7 place
    long g = 1000000;
    long number_remainder_7 = creator(number, g * 10);
    int number_7 = isolator(number_remainder_7, g);

    // Isolating 8 place
    long h = 10000000;
    long number_remainder_8 = creator(number, h * 10);
    int number_8 = isolator(number_remainder_8, h);

    // Isolating 9 place
    long i = 100000000;
    long number_remainder_9 = creator(number, i * 10);
    int number_9 = isolator(number_remainder_9, i);

    // Isolating 10 place
    long j = 1000000000;
    long number_remainder_10 = creator(number, j * 10);
    int number_10 = isolator(number_remainder_10, j);

    // Isolating 11 place
    long k = 10000000000;
    long number_remainder_11 = creator(number, k * 10);
    int number_11 = isolator(number_remainder_11, k);

    // Isolating 12 place
    long l = 100000000000;
    long number_remainder_12 = creator(number, l * 10);
    int number_12 = isolator(number_remainder_12, l);

    // Isolating 13 place
    long m = 1000000000000;
    long number_remainder_13 = creator(number, m * 10);
    int number_13 = isolator(number_remainder_13, m);

    // Isolating 14 place
    long n = 10000000000000;
    long number_remainder_14 = creator(number, n * 10);
    int number_14 = isolator(number_remainder_14, n);

    // Isolating 15 place
    long o = 100000000000000;
    long number_remainder_15 = creator(number, o * 10);
    int number_15 = isolator(number_remainder_15, o);

    // Isolating 16 place
    long p = 1000000000000000;
    long number_remainder_16 = creator(number, p * 10);
    int number_16 = isolator(number_remainder_16, p);

    // Product of even places from right

    // Product 1
    int product_1 = number_2 * 2;
    int product_ones_1 = creator(product_1, 10);
    int product_tens_1 = isolator(product_1, 10);

    // Product 2
    int product_2 = number_4 * 2;
    int product_ones_2 = creator(product_2, 10);
    int product_tens_2 = isolator(product_2, 10);

    // Product 3
    int product_3 = number_6 * 2;
    int product_ones_3 = creator(product_3, 10);
    int product_tens_3 = isolator(product_3, 10);

    // Product 4
    int product_4 = number_8 * 2;
    int product_ones_4 = creator(product_4, 10);
    int product_tens_4 = isolator(product_4, 10);

    // Product 5
    int product_5 = number_10 * 2;
    int product_ones_5 = creator(product_5, 10);
    int product_tens_5 = isolator(product_5, 10);

    // Product 6
    int product_6 = number_12 * 2;
    int product_ones_6 = creator(product_6, 10);
    int product_tens_6 = isolator(product_6, 10);

    // Product 7
    int product_7 = number_14 * 2;
    int product_ones_7 = creator(product_7, 10);
    int product_tens_7 = isolator(product_7, 10);

    // Product 8
    int product_8 = number_16 * 2;
    int product_ones_8 = creator(product_8, 10);
    int product_tens_8 = isolator(product_8, 10);

    // Sum of product digits
    int sum_product_digits_ones = product_ones_1 + product_ones_2 + product_ones_3 +
                                  product_ones_4 + product_ones_5 + product_ones_6 +
                                  product_ones_7 + product_ones_8;
    int sum_product_digits_tens = product_tens_1 + product_tens_2 + product_tens_3 +
                                  product_tens_4 + product_tens_5 + product_tens_6 +
                                  product_tens_7 + product_tens_8;

    int sum_verification = sum_product_digits_ones + sum_product_digits_tens + number_1 + number_3 +
                           number_5 + number_7 + number_9 + number_11 + number_13 + number_15;
    int last_digit_sum_verification = creator(sum_verification, 10);

    if (last_digit_sum_verification != 0)
    {
        printf("Invalid\n");
    }
    else
    {
        if (number_16 == 0 && number_15 == 3 && (number_14 == 4) | (number_14 == 7))
        {
            printf("American Express\n");
        }
        else if (number_16 == 5 && (number_15 == 1) | (number_15 == 2) | (number_15 == 3) |
                                       (number_15 == 4) | (number_15 == 5))
        {
            printf("MasterCard\n");
        }
        else if (number_16 == 4 || number_13 == 4)
        {
            printf("Visa\n");
        }
        else
        {
            printf("Invalid");
        }
    }
}

long creator(long number, long digit)
{
    return number % digit;
}

int isolator(long number_remainder_on_, long digit)
{
    return number_remainder_on_ / digit;
}
