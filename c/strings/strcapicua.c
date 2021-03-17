#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool strcapicua(char *s1, bool ignoreCase);

int main()
{
    char *s1 = "Ana";
    printf("Is %s capicua: %s\n", s1, strcapicua(s1, false) ? "yes" : "no");
    s1 = "Ana";
    printf("Is %s capicua (ignore case): %s\n", s1, strcapicua(s1, true) ? "yes" : "no");
    s1 = "ana";
    printf("Is %s capicua: %s\n", s1, strcapicua(s1, false) ? "yes" : "no");
    s1 = "Ricardo";
    printf("Is %s capicua: %s\n", s1, strcapicua(s1, false) ? "yes" : "no");
    s1 = "assa";
    printf("Is %s capicua: %s\n", s1, strcapicua(s1, false) ? "yes" : "no");
    s1 = "m";
    printf("Is %s capicua: %s\n", s1, strcapicua(s1, false) ? "yes" : "no");
    s1 = "assar";
    printf("Is %s capicua: %s\n", s1, strcapicua(s1, false) ? "yes" : "no");
    return 0;
}

bool strcapicua(char *s1, bool ignoreCase)
{
    int size = strlen(s1);
    for (int i = 0; i <= size - i - 1; i++)
    {
        if (ignoreCase)
        {
            if ((int)s1[i] >= (int)'a' && (int)s1[i] <= (int)'z')
            {
                if ((int)s1[i] - 32 == (int)s1[size - i - 1])
                    continue;
                else
                    return false;
            }
            if ((int)s1[i] >= (int)'A' && (int)s1[i] <= (int)'Z')
            {
                if ((int)s1[i] + 32 == (int)s1[size - i - 1])
                    continue;
                else
                    return false;
            }
            if (s1[i] != s1[size - i - 1])
                return false;
        }
        else
        {
            if (s1[i] != s1[size - i - 1])
                return false;
        }
    }
    return true;
}