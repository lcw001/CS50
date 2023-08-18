#include <cs50.h>
#include <stdio.h>
#include <stdint.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Imprope usage.\n");
        return 1;
    }

// open file
    string filename = argv[1];
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("no such file.\n");
        return 1;
    }

// create buffer
    uint8_t buffer[4];

// make an array that contains buffer values
    uint8_t signature[] = {37, 80, 68, 70};

    fread(buffer,1,4,file);

    for (int i = 0; i < 4; i++)
    {
        printf("%i ", buffer[i]);
    }
    printf("\n");

    // compare buffer to signature buffer for match

    for (int i = 0; i < 4; i++)
    {
        if (buffer[i] != signature[i])
        {
            printf("Likely not a PDF.\n");
            //preents mem leak from keeping file open
            fclose(file);
            return 0;
        }
    }
    printf("Likely a PDF.\n");
    fclose(file);
    return 0;
}
