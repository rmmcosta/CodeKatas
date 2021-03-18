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
    s1 = "AbcDdCBa";
    printf("Is %s capicua: %s\n", s1, strcapicua(s1, false) ? "yes" : "no");
    s1 = "AbcDdCBa";
    printf("Is %s capicua (ignore case): %s\n", s1, strcapicua(s1, true) ? "yes" : "no");
    return 0;
}

bool strcapicua(char *s1, bool ignoreCase)
{
    int size = strlen(s1);
    char leftChar;
    char rightChar;
    for (int i = 0; i < size - i - 1; i++)
    {
        leftChar = s1[i];
        rightChar = s1[size - i - 1];
        if (ignoreCase)
        {

            int leftAscii = (int)leftChar;
            int rightAscii = (int)rightChar;
            if (leftAscii >= (int)'a' && leftAscii <= (int)'z')
            {
                if (leftAscii - 32 == rightAscii)
                    continue;
                else
                    return false;
            }
            if (leftAscii >= (int)'A' && leftAscii <= (int)'Z')
            {
                if (leftAscii + 32 == rightAscii)
                    continue;
                else
                    return false;
            }
        }
        if (leftChar != rightChar)
            return false;
    }
    return true;
}