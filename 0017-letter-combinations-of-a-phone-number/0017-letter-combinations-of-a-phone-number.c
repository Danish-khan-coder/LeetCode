#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *appendChar(char *existing, char ch)
{
    int len = strlen(existing);

    char *newString = malloc(len + 2);

    strcpy(newString, existing);

    newString[len] = ch;
    newString[len + 1] = '\0';

    return newString;
}


void processGroup(
    char **result,
    int resultSize,
    char *group,
    char ***newResult,
    int *newSize
)
{
    *newSize = 0;
    *newResult = NULL;

    for (int i = 0; i < resultSize; i++)
    {
        for (int j = 0; group[j] != '\0'; j++)
        {
            (*newSize)++;

            *newResult = realloc(
                *newResult,
                (*newSize) * sizeof(char *)
            );

            (*newResult)[*newSize - 1] =
                appendChar(result[i], group[j]);
        }
    }
}


char** letterCombinations(char* digits, int* returnSize)
{
    char *mapping[] = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };

    *returnSize = 0;

    if (digits == NULL || digits[0] == '\0')
        return NULL;

    char **result = malloc(sizeof(char *));
    int resultSize = 1;

    result[0] = malloc(1);
    result[0][0] = '\0';

    for (int i = 0; digits[i] != '\0'; i++)
    {
        char *group = mapping[digits[i] - '0'];

        char **newResult;
        int newSize;

        processGroup(
            result,
            resultSize,
            group,
            &newResult,
            &newSize
        );

        for (int j = 0; j < resultSize; j++)
        {
            free(result[j]);
        }

        free(result);

        result = newResult;
        resultSize = newSize;
    }

    *returnSize = resultSize;

    return result;
}
