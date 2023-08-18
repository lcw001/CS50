#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
// program evaluates input for lower case letters and changes to uppercase
    string s = get_string("Before: ");
    printf("After:  ");
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        printf("%c", toupper(s[i]));
    }
    printf(" \n");
}

//----------- OLD WAY ----------------------------------

//        if (islower(s[i]))
//        {
//            printf("%c", toupper(s[i]));
//        }
//        if (s[i] >= 'a' && s[i] <= 'z')
//        {
//          printf("%c", s[i] - 32);
//        }
//        else
//        {
//          printf("%c", s[i]);
//        }