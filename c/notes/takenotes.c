#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h> //gives flags to use when exiting the program

const char *NOTES_FILE_PATH = "/tmp/notes";
const int OPEN_FLAG = O_WRONLY | O_CREAT | O_APPEND;
const int OPEN_MODE = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;

void printErrorMessageAndExit(const char *msg);
void writeStr2File(const int fd, const char *note);
void writeUid2File(const int fd);

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printErrorMessageAndExit("you must specify the notes you want to take as arguments!");
    }
    int fd = open(NOTES_FILE_PATH, OPEN_FLAG, OPEN_MODE);
    if (fd == -1)
        printErrorMessageAndExit("Error opening file");
    writeStr2File(fd, "\n");
    writeUid2File(fd);
    writeStr2File(fd, ":");
    writeStr2File(fd, "\n");
    int currentNotePos = 0;
    while (++currentNotePos < argc)
    {
        char *currentNote = argv[currentNotePos];
        writeStr2File(fd, currentNote);
        writeStr2File(fd, " ");
    }
    writeStr2File(fd, "\n");
    writeStr2File(fd, "\n----  End of File ----\n");
    close(fd);
    printf("Notes have been saved.\n");
    return 0;
}

void printErrorMessageAndExit(const char *msg)
{
    perror(msg);
    exit(EXIT_FAILURE);
}

void writeStr2File(const int fd, const char *note)
{
    if (write(fd, note, strlen(note)) == -1)
        printErrorMessageAndExit("Error writing to file");
}

void writeUid2File(const int fd)
{
    int userid = getuid();
    if (write(fd, &userid, sizeof(int)) == -1)
        printErrorMessageAndExit("Error writing the identification to the file");
}