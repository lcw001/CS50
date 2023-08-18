#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
//  Ask user for length of array
    int length;
    do
    {
        length = get_int("Length: ");
    }
    while (length < 1);

//  Declare the array
    int twice[length];

//  Set first value
    twice[0] = 1;
    printf("i = %i %i\n", twice[0], twice[0]);
    for (int i = 1; i < length; i++)
    {
//      Make current element twice the previous
        twice[i] = 2 * twice[i - 1];

//      Print current element

        printf("i = %i %i\n", i, twice[i]);
    }
}
