#include "cs50.h"
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Asking for text
    string text = get_string("Text: ");
    int length = strlen(text);

    // Determining no. of sentences and words by keeping count of fullstops and spaces
    // Also determining no. of extras to be subtracted to get no. of letters
    double sentences = 0;
    double words = 1;
    int extras = 0;
    for (int i = 0; i < length; i++)
    {
        if ((text[i] == '.') || (text[i] == '?') || (text[i] == '!'))
        {
            sentences++;
        }
        else if (text[i] == ' ')
        {
            words++;
        }
        if (isalpha(text[i]) == 0)
        {
            extras++;
        }
    }

    // Calculating letters, l and s
    double letters = length - extras;
    double l = (letters / words) * 100;
    double s = (sentences / words) * 100;

    // Calculating index
    double index = 0.0588 * l - 0.296 * s - 15.8;
    int grade = round(index);

    // Printing result
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if ((grade >= 1) && (grade < 16))
    {
        printf("Grade %i\n", grade);
    }
    else
    {
        printf("Grade 16+\n");
    }
}
