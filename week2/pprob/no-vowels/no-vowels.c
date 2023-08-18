// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>

string replace_vowels(int argc, string argv[]);

int main(int argc, string argv[])
{
//    printf("argv[1] = %s\n", argv[1]);
//----------------------------------------------------------------
// evaluate each character for vowel
    for (int i = 0, len = strlen(argv[1]); i < len; i++)
    {
        // switch variable
        char x = argv[1][i];
        //    printf("x = %i  ", x);

// switch statements
        switch (x)
        {
            case 65:
                x = 54;
                break;
            case 97:
                x = 54;
                break;
            case 69:
                x = 51;
                break;
            case 101:
                x = 51;
                break;
            case 73:
                x = 49;
                break;
            case 105:
                x = 49;
                break;
            case 79:
                x = 48;
                break;
            case 111:
                x = 48;
                break;
            case 85:
                x = 85;
                break;
            case 117:
                x = 117;
                break;
            default:
                break;
                return x;
        }
        //    printf("%c ", argv[1][i]);
        //printf("argv[1][%i] = %c", i, x);
        printf("%c", x);
    }
    printf("\n");
}

//string replace_vowels(int argc, string argv[])
//{
// evaluate each character for vowel
//    for (int i = 0, len = strlen(argv[1]); i < len; i++)
//    {
//    switch variable
//    char x = argv[1][i];
//    printf("x = %i\n", x);
// switch statements
//    switch (x)
//    {
//        case int x = 65:
//            x = 54;
//            break;
//
//        case argv[1][i] = 'E':
//            argv[1][i] = '3';
//            break;
//
//        case argv[1][i] = 'I':
//            argv[1][i] = '1';
//            break;
//
//        case argv[1][i] = 'O':
//            argv[1][i] = '0';
//            break;
//
//        case argv[1][i] = 'U':
//            argv[1][i] = 'U';
//            break;
//
//        default:
//            break;
//        return x;
//    }
// }