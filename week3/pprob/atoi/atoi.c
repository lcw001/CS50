#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
    
}

int convert(string input)
{
//    char c [strlen(input)];
//    for (int i = 0, n = strlen(input); i < n; i++)
//    {
//        c[i] = input[i];
//    }
      return atoi(input);
}