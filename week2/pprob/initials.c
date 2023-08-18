#include<cs50.h>
#include<stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
// prints initials (first letter) in string added on command line
// ./initials Larry Ward
//  output = L W
    printf("Initials = %c %c\n", argv[1][0], argv[2][0]);
    int argv1len = strlen(argv[1]);
    int argv2len = strlen(argv[2]);
    int argv12len = strlen(argv[1]) + strlen(argv[2]);
    printf("argv[1] length = %i\n", argv1len);
    printf("argv[2] length = %i\n", argv2len);
    printf("argv[1] and argv[2] length = %i\n", argv12len);
    }