#include <stdio.h>
#include <stdlib.h>

const int INT_SIZE = 32;

void displayInBinary(unsigned int theNumber);

//retrieved from the book 'The Art of Exploitation'
void binaryPrint(unsigned int value);
char *int2BinaryString(unsigned int value);

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("Please input the number or numbers (as input parameters) that you wish to display in binary.\n");
        exit(-1);
    }
    int currentArgPos = 0;
    int currentArg;
    while (++currentArgPos < argc)
    {
        currentArg = atoi(argv[currentArgPos]);
        printf("\n---- %d ----\n", currentArg);
        displayInBinary(currentArg);
        binaryPrint(currentArg);
        printf("%s\n", int2BinaryString(currentArg));
    }
    return 0;
}

void displayInBinary(unsigned int theNumber)
{
    int currentPosition = 0;
    char boolDigits[INT_SIZE];
    for (int i = 0; i < INT_SIZE; i++)
        boolDigits[i] = 0;
    while (theNumber / 2 >= 1)
    {
        boolDigits[currentPosition++] = theNumber % 2;
        theNumber /= 2;
    }
    boolDigits[currentPosition] = 1;
    for (currentPosition = 31; currentPosition >= 0; currentPosition--)
    {
        if ((currentPosition + 1) % 8 == 0)
            printf(" ");
        printf("%d", boolDigits[currentPosition]);
    }
    printf("\n");
}

void binaryPrint(unsigned int value)
{
    unsigned int mask = 0xff000000;       //start with a mask for the highest byte
    unsigned int shift = 256 * 256 * 256; //start with a shift for the highest byte
    unsigned int byte;
    short int byteIterator, bitIterator;
    for (byteIterator = 0; byteIterator < 4; byteIterator++)
    {
        //printf("value & mask = %b\n", value & mask);
        //printf("(value&mask)/shift = %b\n", (value & mask) / shift);
        byte = (value & mask) / shift; //isolate each byte
        printf(" ");
        //print the byte's bits
        for (bitIterator = 0; bitIterator < 8; bitIterator++)
        {
            if (byte & 0x80) //if the highest bit isn't 0
                printf("1");
            else
                printf("0");
            byte *= 2; //shift all bits to the left by 1
            //equivalent to byte << 1, shift to the left = x*2^y, shift to the right = x/2^y
            //printf("\n%b", byte);
        }
        mask /= 256;  //shift bits of the mask to the right by 8
        shift /= 256; //shift bits of the shift to the right by 8;
    }
    printf("\n");
}

char *int2BinaryString(unsigned int value)
{
    char *binaryStr = (char *)malloc(sizeof(char) * 32 + 4);
    unsigned int mask = 0xff000000, byte;
    short int shift = 24, byteIterator, bitIterator;
    for (byteIterator = 0; byteIterator < 4; byteIterator++)
    {
        *(binaryStr + byteIterator * 9) = ' ';
        byte = (value & mask) >> shift; //put the highest byte as the lowest byte
        for (bitIterator = 0; bitIterator < 8; bitIterator++)
        {
            //always check the highest bit and shift bits to the left by 1
            if (byte & 0x80)
                *(binaryStr + byteIterator * 8 + bitIterator + (byteIterator + 1)) = '1';
            else
                *(binaryStr + byteIterator * 8 + bitIterator + (byteIterator + 1)) = '0';
            byte = byte << 1;
        }
        mask = mask >> 8;
        shift -= 8;
    }
    return binaryStr;
}