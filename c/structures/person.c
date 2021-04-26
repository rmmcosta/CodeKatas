#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int day;
    char month[15];
    int year;
} Date;

typedef struct
{
    char name[100];
    Date birthdate;
    char phoneNumber[20];
} Person;

void presentPerson(const Person *person);
void newPerson(Person *person);

int main(void)
{
    Person p1 = {"Ricardo Costa", {10, "October", 1985}, "+351914423167"};
    presentPerson(&p1);
    Person p2 = {"Ana Ramos", {15, "April", 1983}, "+351966945019"};
    presentPerson(&p2);
    newPerson(&p2);
    presentPerson(&p2);
    Person *p3 = malloc(sizeof(Person));
    newPerson(p3);
    presentPerson(p3);
    free(p3);
    return 0;
}

void presentPerson(const Person *person)
{
    printf("****  %s  ****\n", person->name);
    printf("\tBirth date: %d %s %d\n", person->birthdate.day, person->birthdate.month, person->birthdate.year);
    printf("\tPhone: %s\n", person->phoneNumber);
}

void newPerson(Person *person)
{
    printf("Please input the person name:");
    scanf("%[^\n]", person->name);
    printf("Please input the birthdate (day month year):");
    scanf("%d %s %d", &person->birthdate.day, person->birthdate.month, &person->birthdate.year);
    scanf("%*[^\n]");
    scanf("%*c");
    printf("Please input the phone number:");
    scanf("%[^\n]", person->phoneNumber);
    scanf("%*[^\n]");
    scanf("%*c");
}