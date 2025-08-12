#include "cs50.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

string case_adjuster(string word);
int score_calc(string cleared_word);

int main(void)
{
    // Input for players
    string word_1 = get_string("Player 1: ");
    string word_2 = get_string("Player 2: ");

    // Comparing scores
    int score_1 = score_calc(case_adjuster(word_1));
    int score_2 = score_calc(case_adjuster(word_2));

    // Result
    if (score_1 > score_2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score_1 < score_2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

// Uppercase letters to lower case letter by if condition on for loop
string case_adjuster(string word)
{
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        if (isupper(word[i]) != 0)
        {
            word[i] = tolower(word[i]);
        }
    }
    return word;
}

// Calculating scores by applying if else conditions on loop
int score_calc(string cleared_word)
{
    int score = 0;
    for (int i = 0, n = strlen(cleared_word); i < n; i++)
        if ((cleared_word[i] == 'a') || (cleared_word[i] == 'e') || (cleared_word[i] == 'i') ||
            (cleared_word[i] == 'l') || (cleared_word[i] == 'n') || (cleared_word[i] == 'o') ||
            (cleared_word[i] == 'r') || (cleared_word[i] == 's') || (cleared_word[i] == 't') ||
            (cleared_word[i] == 'u'))
        {
            score++;
        }
        else if ((cleared_word[i] == 'd') || (cleared_word[i] == 'g'))
        {
            score += 2;
        }
        else if ((cleared_word[i] == 'b') || (cleared_word[i] == 'c') || (cleared_word[i] == 'm') ||
                 (cleared_word[i] == 'p'))
        {
            score += 3;
        }
        else if ((cleared_word[i] == 'f') || (cleared_word[i] == 'h') || (cleared_word[i] == 'v') ||
                 (cleared_word[i] == 'w') || (cleared_word[i] == 'y'))
        {
            score += 4;
        }
        else if (cleared_word[i] == 'k')
        {
            score += 5;
        }
        else if ((cleared_word[i] == 'j') || (cleared_word[i] == 'x'))
        {
            score += 8;
        }
        else if ((cleared_word[i] == 'q') || (cleared_word[i] == 'z'))
        {
            score += 10;
        }
        else
        {
            score += 0;
        }
    return score;
}
