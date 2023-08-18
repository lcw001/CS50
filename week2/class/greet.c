#include <cs50.h>
#include <stdio.h>

// if coding command line arguments add to int main()
// int argc - count or length of array
// string argv[] - array containing all of the words typed at prompt

// type ./greet Larry to start program.. automatically adds to output.
// greet[0] = ./greet
// greet[1] = Larry
int main(int argc, string argv[])
{
    if (argc == 2)
    {
        printf("Hello %s\n", argv[1]);
    }
    else
    {
        printf("Hello World \n");
    }
//    printf("hello, %s\n", argv[1]);
}