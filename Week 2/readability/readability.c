#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int score_text(int letters, int words, int sentences);

int main(void)
{
    // Get input text.
    string input = get_string("Text: ");

    // Count the number of letters input.
    int letters = count_letters(input);

    // Count the number of words input.
    int words = count_words(input);

    // Count the number of sentences input.
    int sentences = count_sentences(input);

    // Calculate the grade level.
    int grade = score_text(letters, words, sentences);

    // Output the result.
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

int count_letters(string text)
{
    // Count the total number of letters input.
    int count = 0;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isupper(text[i]) || islower(text[i]))
        {
            count += 1;
        }
    }

    return count;
}

int count_words(string text)
{
    // Count the total number of words input, start at 1 to account for the last word that does not have a space.
    int count = 1;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isspace(text[i]))
        {
            count += 1;
        }
    }

    return count;
}

int count_sentences(string text)
{
    // Count the total number of sentences input.
    int count = 0;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (((text[i] - '.') == 0) || ((text[i] - '!') == 0) || ((text[i] - '?') == 0))
        {
            count += 1;
        }
    }

    return count;
}

int score_text(int letters, int words, int sentences)
{
    // Calculate the grade level.
    double L = (double) letters * 100.0 / words;
    double S = (double) sentences * 100.0 / words;

    int index = round(0.0588 * L - 0.296 * S - 15.8);

    return index;
}