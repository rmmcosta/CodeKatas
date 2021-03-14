#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

const int LINES = 7;
const int COLUMNS = 7;
const int MINBETS = 6;
const int MAXBETS = 49;
const int MAXDIGITS = 2;
const int MINNUM = 1;

int getNums2Bet();
void generateRandBets(int randBets[], int size);
void printBet(int randBets[], int numOfBets);
bool isBet(int number, int randBets[], int numOfBets);
bool isAlreadyBet(int randBets[], int numOfBets, int bet);

int main()
{
    while (true)
    {
        int nums2Bet = getNums2Bet();
        int randBets[nums2Bet];
        generateRandBets(randBets, nums2Bet);
        printBet(randBets, nums2Bet);
    }
    return 0;
}

void printBet(int randBets[], int numOfBets)
{
    printf("\n");
    for (int i = MINNUM; i <= LINES * COLUMNS; i++)
    {
        if (isBet(i, randBets, numOfBets))
            printf("XX");
        else
            printf("%2d", i);
        if (i % COLUMNS == 0)
            printf("\n\n");
        else
            printf(" ");
    }
}

bool isBet(int number, int RandBets[], int numOfBets)
{
    for (int i = 0; i < numOfBets; i++)
        if (RandBets[i] == number)
            return true;
    return false;
}

void generateRandBets(int randBets[], int size)
{
    long ultime;
    time(&ultime);
    srand(ultime);
    int max = LINES * COLUMNS;
    for (int i = 0; i < size; i++)
    {
        int randBet = 0;
        do
        {
            randBet = rand() % max + MINNUM;
        } while (isAlreadyBet(randBets, i, randBet));
        randBets[i] = randBet;
    }
}

bool isAlreadyBet(int randBets[], int numOfBets, int bet)
{
    for (int i = 0; i < numOfBets; i++)
    {
        if (randBets[i] == bet)
            return true;
    }
    return false;
}

int getNums2Bet()
{
    char s[MAXDIGITS];
    int tries = 0;
    do
    {
        if (tries > 0)
        {
            //clear the buffer
            scanf("%*[^\n]");
            scanf("%*c");
        }
        printf("How many numbers do you want to bet (min - %d, max - %d, 0 - terminate)? ", MINBETS, MAXBETS);
        scanf(" %[0-9{1,2}]", s);
        if (atoi(s) == 0)
            exit(0);
        tries++;
    } while (atoi(s) < MINBETS || atoi(s) > MAXBETS);
    return atoi(s);
}