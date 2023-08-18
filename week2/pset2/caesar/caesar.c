#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int one_argc(int argc);
bool only_digits(string str);
int rotate_plaintext(string plaintext, int count);

//------------------------------------------------------MAIN
int main(int argc, string argv[])
{
    //------------checks for only one argc-----------------
    int digitcheck = (int) one_argc(argc);
    if (digitcheck != 0)
    {
        printf("Usage: ./ceaser key\n");
        return 1;
    }

    //------------checks for only digits in argv[1]---------
    string str = argv[1];

    // int digitonly = only_digits(str);
    bool digitonly = only_digits(str);
    if (digitonly != true)
    {
        return 1;
    }

    //------------Ask user to input plaintext---------------
    string plaintext = get_string("plaintext: ");
    int count = atoi(argv[1]);

    // rotate alpha characters
    int len = strlen(plaintext);
    char ciphertext = rotate_plaintext(plaintext, count);
}

//------------------------------------------------FUNCTIONS
//-----------------------------------------only single argc
int one_argc(int argc)
{
    if (argc != 2)
    {
        return 1;
    }
    return 0;
}

//----------------------------------------------only digits
bool only_digits(string str)
{
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        char x = str[i];
        bool digitest = isdigit(x);
        if (digitest != true)
        {
            printf("Usage: ./caesar key\n");
            return 0;
        }
    }
    return 1;
}

//--------------------------------rotate int of plaintext
int rotate_plaintext(string plaintext, int count)
{
    char ciphertext;
    string rotatetext;
    string letter = "";
    int len = strlen(plaintext);

    printf("ciphertext: ");

    for (int i = 0; i < len; i++)
    {
        char x = (plaintext[i]);
// check plaintext for letters and non-letters
// only rotate letters
        int check = isalpha(x);

        if (check)
        {

// checks for uppercase letters
            if (isupper(x))
            {
                ciphertext = (((x + count) - 65) % 26) + 65;
                printf("%c", ciphertext);
            }

// checks for lowercase letters
            else if (islower(x))
            {
                ciphertext = (((x + count) - 97) % 26) + 97;
                printf("%c", ciphertext);
            }
        }
// print non alpha characters
        else
        {
            printf("%c", x);
        }
    }
    printf("\n");
    return 0;
}