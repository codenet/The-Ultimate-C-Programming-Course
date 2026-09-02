#include <stdio.h>

struct employee
{
    int code; // This declares a new user defined data type!
    float salary;
    char name[10];
}; // semicolon is important

int main()
{
    struct employee iitd[100]; // an array of structures
    // we can access the data using:
    iitd[0].code = 100;
    iitd[1].code = 77;
    return 0;
}
