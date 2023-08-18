// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{

    bool aUpper = false, aLower = false, aNumber = false, aSymbol = false;

    for (int i = 0, len = strlen(password); i < len; i++)
    {
        char x = password[i];
        if (isupper(password[i]))
        {
            aUpper = true;
        }
        else if (islower(password[i]))
        {
            aLower = true;
        }
        else if (isdigit(password[i]))
        {
            aNumber = true;
        }
        else if ((x >= 33 && x < +47) || (x >= 58 && x <= 64) || (x >= 91 && x <= 96) || (x >= 123 && x <= 126))
        {
            aSymbol = true;
        }
        if (aUpper && aLower && aNumber && aSymbol)
        {
            return true;
        }
    }
    return false ;
}