#include "cs50.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int ALP_SIZE = 26;
int main(int argc, string argv[])
{
    // Validating command line argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Insuring command line aregument[1] is numeric digit
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
        if (isdigit(argv[1][i]) == 0)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }

    // Converting string digits to int digits
    int key = atoi(argv[1]);

    // Asking for Input for coversion
    string plaintext = get_string("Plaintext:  ");
    const int LEN = strlen(plaintext);

    // Making copy of input
    char ciphertext[LEN + 1];
    strcpy(ciphertext, plaintext);

    // Creating loop for ciphering capital and small letters by applying formula
    // (letter-ascii+key)%26 +ascii
    for (int i = 0, n = LEN; i < n; i++)
    {
        if (isupper(ciphertext[i]) != 0)
        {
            ciphertext[i] = ((ciphertext[i] - 'A' + key) % ALP_SIZE) + 'A';
        }
        else if (islower(ciphertext[i]) != 0)
        {
            ciphertext[i] = ((ciphertext[i] - 'a' + key) % ALP_SIZE) + 'a';
        }
    }

    // Print ciphertext
    printf("ciphertext: %s\n", ciphertext);
    return 0;
}
