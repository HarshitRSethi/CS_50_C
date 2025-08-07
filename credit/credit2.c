#include "cs50.h"
#include <stdio.h>

int place_extractor(long number, long digit);

int main(void)
{
  long number;
    do
    {
        number = get_long("Number: ");
    }
    while (number < 0 || number > 9999999999999999);

    int sum_even_digits_final = 0;
    int sum_odd_digits_final = 0;
    long a = 100;
    long b = 10;

  // Extracting 16,15,14 and 13th digit from right.
  int number_16 = place_extractor(number, 1000000000000000);
  int number_15 = place_extractor(number, 100000000000000);
  int number_14 = place_extractor(number,10000000000000);
  int number_13 = place_extractor(number, 1000000000000);
  printf("%i", number_16);


  // Loop for gaining sum of even place digits (From right) for Luhan's Algorithm.
  for ( int i = 0; i < 8; i++)
  {
    long remainder = (number % a);
    remainder = (remainder) / (a / 10);
    remainder *= 2;
    int remainder_1 = remainder % 10;
    int remainder_2 = remainder / 10;
    sum_even_digits_final += remainder_1 + remainder_2;
    a *= 100;
  }

  // Loop for gaining sum of odd place digits (From right) for Luhan's Algorith.
  for ( int i = 0; i < 8; i++)
  {
    long remainder = (number % b);
    remainder = (remainder) / (b / 10);
    sum_odd_digits_final += remainder;
    b *= 100;
  }
  // Finalising Sum
  int sum = (sum_even_digits_final + sum_odd_digits_final) % 10;

  // Output Code
  if (sum != 0)
  {
    printf("Invalid\n");
  }
  else if (number_16 ==0 && ((number_15 ==1) || (number_15 == 2) || (number_15 == 3) || (number_15 == 4) || (number_15 == 5)))
  {
    printf("American Express\n");
  }
  else if (number_16 == 5 && ((number_15 == 1) || (number_15 == 2 ) || (number_15 == 3) || (number_15 == 4) || (number_15 == 5)))
  {
    printf("MasterCard\n");
  }
  else if (number_16 ==4 || number_13 == 4)
  {
    printf("Visa\n");
  }
  else
  {
    printf("Invalid\n");
  }


}

int place_extractor(long number, long digit)
{
  long number_remainder_on_ = number % (digit * 10);
  return (int) number_remainder_on_ / (digit);
}