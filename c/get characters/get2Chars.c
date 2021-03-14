#include <stdio.h>
#include <stdbool.h> //only works in c99 or newer
// otherwise we can define an enum for bool
// typedef enum {true, false} bool;

char getLetter(char *msg);
bool isLetter(char ch);

int main()
{
    char ch1;
    char ch2;
    ch1 = getLetter("Please enter one letter: ");
    ch2 = getLetter("Please enter another letter: ");
    printf("You entered 2 letters %c and %c\n", ch1, ch2);
    printf("asci codes a:%d z:%d A:%d Z:%d\n", 'a', 'z', 'A', 'Z');
    return 0;
}

char getLetter(char *msg)
{
    char c;
    bool aLetter = false;
    const char *removeEnter = "\n\r";
    while (!aLetter)
    {
        printf("%s", msg);
        scanf(" %c", &c);
        aLetter = isLetter(c);
    }
    return c;
}

bool isLetter(char ch)
{
    int asciiCode = (int)ch;
    if ((asciiCode >= 97 && asciiCode <= 122) || (asciiCode >= 65 && asciiCode <= 90))
        return true;
    return false;
}