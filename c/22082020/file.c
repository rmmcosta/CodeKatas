#include "file.h"

void open(char *nome, int mode)
{
}

void close()
{
}

int read()
{
    int c;
    return c * 10;
}

void write(char c)
{
}

void seek(long index, int mode)
{
}

struct FILE console = {open, close, read, write, seek};

extern struct FILE *STDIN = &console;

int getchar()
{
    return STDIN->read();
}