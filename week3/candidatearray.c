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
    candidate candidates_array[3];
    for (int i = 0; i < 3; i++)
    {
        candidates_array[i] = get_candidate("Enter a candidate: ");

    }

    for (int i = 0; i < 3; i++)
    {
                printf("candidate: %s  votes: %i\n", candidates_array[i].name, candidates_array[i].votes);
    }
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
