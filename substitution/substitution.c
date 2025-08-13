#include "cs50.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

const int ALPH_SIZE = 26;

char substitute_character(string text1, char array[], int i, int ascii);

int main(int argc, string argv[])
{
    // Create a CLI i.e. reject cla's like multiple clas, not alphabetic letter, not 26 letters,
    // repetation in letter etc
    //  Multiple cla checker
    if (argc != 2)
    {
        printf("Usage: ./ substitution key\n");
        return 1;
    }

    // Key length checker
    if (strlen(argv[1]) != ALPH_SIZE)
    {
        printf("Key must contain 26 charecters\n");
        return 1;
    }

    // Only alphabatical charecter checker
    for (int i = 0; i < ALPH_SIZE; i++)
    {
        if (isalpha(argv[1][i]) == 0)
        {
            printf("Key should be alphabatical\n");
            return 1;
        }
    }

    // Converting lowercase charecter to uppercase key
    char KEY[ALPH_SIZE + 1];
    KEY[ALPH_SIZE] = '\0';
    for (int i = 0; i < ALPH_SIZE; i++)
    {
        KEY[i] = toupper(argv[1][i]);
    }

    // Stop from repeatation
    for (int i = 0; i < ALPH_SIZE; i++)
    {
        int charecter = 0;
        int appear = 0;
        for (int j = 0; j < ALPH_SIZE; j++)
        {
            if (KEY[i] != KEY[charecter])
            {
                charecter++;
            }
            else
            {
                charecter++;
                appear++;
            }
        }
        if (appear >= 2)
        {
            printf("Key must not contain repeated charecter");
            return 1;
        }
    }

    // Lowercase key
    char key[ALPH_SIZE + 1];
    key[ALPH_SIZE] = '\0';
    for (int i = 0; i < ALPH_SIZE; i++)
    {
        key[i] = KEY[i] + ('a' - 'A');
    }

    // Ask for input
    string plaintext = get_string("plaintext:  ");
    int const LEN = strlen(plaintext);
    char ciphertext[LEN + 1];
    ciphertext[LEN] = '\0';

    // Ciphering the input by replacing according to key provided by user
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if (isupper(plaintext[i]) != 0)
        {
            ciphertext[i] = substitute_character(plaintext, KEY, i, 'A');
        }
        else if (islower(plaintext[i]) != 0)
        {
            ciphertext[i] = substitute_character(plaintext, key, i, 'a');
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }

    // Printing out ciphered output
    {
        printf("ciphertext: %s\n", ciphertext);
    }
}

char substitute_character(string text1, char array[], int i, int ascii)
{
    return array[text1[i] - ascii];
}
