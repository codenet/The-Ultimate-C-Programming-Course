#include <stdio.h>
#include <string.h>

int main()
{
    char s1[56] = "Hello";
    char s2[56] = " world";

    char target[56];
    strcpy(target, s1); // target now contains "Hello"
    printf("st=%s target=%s\n", s1, target);

    strcat(s1, s2); // s1 now contains "Hello world" <no space in between>
    printf("s1=%s\n", s1);

    int a = strcmp("hello", "world"); // negative
    printf("%d\n", a);

    int b = strcmp("world", "hello"); // positive
    printf("%d\n", b);

    int c = strcmp(" world", s2); // zero
    printf("%d\n", c);

    return 0;
}
