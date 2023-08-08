#include <stdio.h>

/**
 * @brief Compair 2 string 
 * 
 * @param str1 
 * @param str2 
 * @return int - 1 if same string, 0 if not
 */
int compair2str(const char *str1, const char *str2)
{
    while (*str1 != '\0')
    {
        // printf("str1 vs str2: %c vs %c\n", *str1++, *str2++);
        if (*str1++ != *str2++)
        {
            return 0;
        }
    }

    // last char must be \0
    return (*str1 == *str2);
}

void countOccurr(char *text)
{
    int MAX_WORDS = 0;
    while (text[MAX_WORDS] != 0)
    {
        MAX_WORDS++;
    }

    char words[MAX_WORDS][MAX_WORDS];
    int count[MAX_WORDS];
    int numWords = 0;

    int i = 0;
    // Loop all array
    while (text[i] != '\0')
    {
        while (text[i] == ' ')
        {
            i++;
        }

        int j = 0;

        // seperate each word by ' ' or '\0' if this is the last string
        while (text[i] != ' ' && text[i] != '\0')
        {
            words[numWords][j] = text[i];
            j++;
            i++;
        }
        // every last string must have \0
        words[numWords][j] = '\0';
        numWords++;
    }

    // Compair every memeber of array and mark wordCount in counts[]
    for (int i = 0; i < numWords; i++)
    {
        if (count[i] != -1)
        {
            int wordCount = 1;
            // compair to next word.
            for (int j = i + 1; j < numWords; j++)
            {
                // printf("%s vs %s\n", words[i], words[j]);
                if (compair2str(words[i], words[j]))
                {
                    wordCount++;
                    count[j] = -1;
                }
            }
            count[i] = wordCount;
        }
    }

    for (int i = 0; i < numWords; i++)
    {
        if (count[i] > 0)
        {
            printf("%s xuat hien %d lan\n", words[i], count[i]);
        }
    }
}

int main()
{
    char text[] = "nhat hoang tuan nam nhat tuan hoang nhat nam bao quoc nam";

    countOccurr(text);

    return 0;
}
