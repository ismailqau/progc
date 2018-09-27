/* -----------------------
 ____  _  _   __   _  _
(__  )/ )( \ / _\ / )( \
 / _/ ) __ (/    \\ /\ /
(____)\_)(_/\_/\_/(_/\_)
-------------------------- */
/**
 * @file
 * @brief Prints the amount of words and characters of the user input
 */
#include "countWords.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_SIZE 256

char *readAndParseInput(char *text)
{
    fgets(text, MAX_STRING_SIZE, stdin);
    if ((strlen(text) > 0) && (text[strlen(text) - 1] == '\n'))
        text[strlen(text) - 1] = '\0';

    return text;
}

/**
 * @brief Main entry point.
 * @returns Returns EXIT_SUCCESS (=0) on success,
 */
int main(void)
{
    int wordCount = 0;
    int charCount = 0;
    char *text = (char *)malloc(MAX_STRING_SIZE);

    if (text != NULL)
    {
        text = readAndParseInput(text);
        charCount = strlen(text);
        wordCount = countWords(text);
    }

    (void)printf("Anzahl Zeichen:\t%3d\n", charCount);
    (void)printf("Anzahl Wörter:\t%3d\n", wordCount);

    return EXIT_SUCCESS;
}
