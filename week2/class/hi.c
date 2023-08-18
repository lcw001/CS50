#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string s ="HI!";
// Prints the string s
//    printf("%s\n", s);

//-------------------
// char H  =  int 73
// char I  =  int 72
// char !  =  int 33
//-------------------


// Prints the char in the array holding the string
//    printf("%c%c%c\n", s[0], s[1], s[2]);

// Prints the int in the array PLUS the 4th position holding the NUL (0)
   printf("%i %i %i %i\n", s[0], s[1], s[2], s[3]);

// Array view of string "HI!BYE!"
//   H          I            !            /0            B            Y            E            !            /0
// words[0][0]  words[0][1]  words[0][2]  words[0][3]  words[1][0]  words[1][1]  words[1][2]  words[1][3]  words[1][4]

}