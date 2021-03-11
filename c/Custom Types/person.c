#include <stdio.h>

struct Person {
    char *firstName;
    char *lastName;
    char *phoneNumber;
};

int main(int argc, char *argv[]) {
    struct Person p;
    if(argc != 4) {
        printf("Wrong console parameters\n");
        return 1;
    } else {
        p.firstName = argv[1];
        p.lastName = argv[2];
        p.phoneNumber = argv[3];
    }
    printf("The person: %s, %s %s\n", p.lastName, p.firstName, p.phoneNumber);
}