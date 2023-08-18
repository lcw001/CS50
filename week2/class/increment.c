#include<cs50.h>
#include<stdio.h>

int increment(int x);

int main(void)
{
    int x = 1;
    int y;
    y = increment(x);

    // will print x is 1, y is 2
    printf("x is %i, Y is %i\n", x, y);

    // need to reassign main x to fxn x
    x = increment(x);
    printf("x is %i, Y is %i\n", x, y);
}

    // the value of fxn x does not pass back up to main x
    int increment(int x)
    {
        x++;
        printf("fxn x = %i\n", x);
        return x;
    }