#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    if (argc !=2)
    {
        printf("Missing command-line input \n");
    }
    else
    {
        printf("hello, %s\n", argv[1]);
        return 0;
    }
}