#include <cs50.h>
#include <stdio.h>

int main(void)
{
// Prompt user for pyramid height
    int height = 0;
    do
    {
        height = get_int("Height? ");
    }
    while (height < 1 || height > 8);
//    printf("Stored: %i\n", height);

// Print pyramid
    int i = 1;
// Rows
    for (int n = height; n > 0; n--)
    {
        int j;
// spaces and #
        for (j = 0; j < n - 1; j++)
        {
            printf(" ");
        }
        int k = j;
        while (height - k > 0)
        {
            printf("#");
            k++;
        }
        printf("\n");
    }
}