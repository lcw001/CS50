#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>


// candidate struct
typedef struct
{
    string name;
    int votes;
}
candidate;

candidate get_candidate(string prompt);

int main(void)
{
    candidate president = get_candidate("Enter a candidate: ");
    printf("%s\n", president.name);
    printf("%i\n", president.votes);
}

//-----------------------------------------------
candidate get_candidate(string prompt)
{
    printf("%s\n", prompt);
    candidate c;
    c.name = get_string("Enter a name: ");
    c.votes = get_int("Enter votes: ");
    return c;
}
