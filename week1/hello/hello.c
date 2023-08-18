#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // User name input
    string name = get_string("What is your name? ");

    // Output
    printf("hello, %s\n", name);
}