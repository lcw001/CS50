#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int start;
    // int year = 0;

    do
    {
        start = get_int("What is your starting size? ");
    }
    while (start < 9);

    // TODO: Prompt for end size
    int end;
    do
    {
        end = get_int("What is your ending size? ");


    }
    while (end < start);

    // TODO: Calculate number of years until we reach threshold
    // Each year 1/3 current llamas born and 1/4 die
    int number = start;
    int year = 0;
    if (start == end)
    {
        year = 0;
    }
    else
    {
        do
        {
            year++;
            number += (start / 3 - start / 4);
            start = number;
        }
        while (number < end);
    }

    // TODO: Print number of years
    printf("Years: %i\n", year);
}
