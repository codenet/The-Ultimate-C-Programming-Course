#include <stdio.h>
#include <string.h>

typedef struct employee
{
    int code; // This declares a new user defined data type!
    float salary;
    char name[10];
} Emp; // semicolon is important

void show(struct employee* ptr){
    printf("%d %f %s\n", ptr->code, ptr->salary, ptr->name);
}

int main(){
    Emp e1;
    Emp* ptr = &e1;

    e1.code = 4511;
    strcpy(e1.name, "Harry");
    e1.salary = 54.44;

    show(ptr);
    
    return 0;
}
