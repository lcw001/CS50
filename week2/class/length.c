#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string name = get_string("What is your name? ");
//-----------------------------------------------------------------------
// CALCULATE LENGTH OF STRING name[]
//looks at entered name one character at a time. first letter is name[0].
// is it = /0?  if yes print.  if no then add 1 to n.  checks name[1].
// = /0
// yes, print
// no, add 1 to end and evaluate 3rd letter : name[2]
// ... to end of word

//    int n = 0;
//    while (name[n] != '/0)
//    {
//        n++;
//    }
//    printf("%i\n", n);
//----------------------------------------------------------------------
    int n = strlen(name);
    printf("%i\n", n);
}


