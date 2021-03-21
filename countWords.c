#include <stdio.h>

#define IN 1
#define OUT 0

int main()
{
    int c, nl = 0, nc = 0, nw = 0, state = IN;
    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
        {
            state = OUT;
            ++nl;
            continue;
        }
        if (c == ' ' || c == '\t')
        {
            state = OUT;
            continue;
        }
        if (state == OUT)
        {
            state = IN;
            ++nw;
        }
        ++nc;
    }
    if (state == OUT)
        ++nw;
    printf("chars:%d, words:%d, lines:%d, state:%d\n", nc, nw, nl, state);
}