#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

int get_cents(void)
{
//  Asks user for input
    int cents;
    do
    {
        cents = get_int("Change owed? ");
    }
    while (cents < 1);
//    printf("Change owed: %i\n", cents);
//    printf("quarters = %i\n", quarters);

    return cents;
}

int calculate_quarters(int cents)
{
//  Calculates number of quarters needed
    int quarters;
    if (cents < 25)
    {
        quarters = 0;
    }
    if (cents > 24 && cents < 50)
    {
        quarters = 1;
    }
    if (cents > 49 && cents < 75)
    {
        quarters = 2;
    }
    if (cents > 74)
    {
        quarters = 3;
    }
    if (cents > 99 && cents < 125)
    {
        quarters = 4;
    }
    if (cents > 125 && cents < 150)
    {
        quarters = 5;
    }
    if (cents > 149 && cents < 175)
    {
        quarters = 6;
    }
    if (cents > 174 && cents < 200)
    {
        quarters = 7;
    }
//    printf("number of quarters = %i\n", quarters);
    return quarters;
}

int calculate_dimes(int cents)
{
//  Calculates number of dimes needed
    int dimes;
    if (cents < 10)
    {
        dimes = 0;
    }
    if (cents > 9 && cents < 20)
    {
        dimes = 1;
    }
    if (cents > 19 && cents < 30)
    {
        dimes = 2;
    }
    if (cents > 29 && cents < 40)
    {
        dimes = 3;
    }
    if (cents > 39 && cents < 50)
    {
        dimes = 4;
    }
    if (cents > 49 && cents < 60)
    {
        dimes = 5;
    }
    if (cents > 59 && cents < 70)
    {
        dimes = 6;
    }
    if (cents > 69 && cents < 80)
    {
        dimes = 7;
    }
    if (cents > 79 && cents < 90)
    {
        dimes = 8;
    }
    if (cents > 89 && cents < 100)
    {
        dimes = 9;
    }
    if (cents > 99 && cents < 110)
    {
        dimes = 10;
    }
//    printf("number of dimes = %i\n", dimes);
    return dimes;
}

int calculate_nickels(int cents)
{
//  Calculates number of nickels needed
    int nickels;
    if (cents < 5)
    {
        nickels = 0;
    }
    if (cents > 4 && cents < 10)
    {
        nickels = 1;
    }
    if (cents > 14 && cents < 20)
    {
        nickels = 3;
    }
    if (cents > 19 && cents < 25)
    {
        nickels = 4;
    }
    if (cents > 24 && cents < 30)
    {
        nickels = 5;
    }
    if (cents > 29 && cents < 35)
    {
        nickels = 6;
    }
    if (cents > 34 && cents < 40)
    {
        nickels = 7;
    }
    if (cents > 39 && cents < 45)
    {
        nickels = 8;
    }
    if (cents > 44 && cents < 50)
    {
        nickels = 9;
    }
    if (cents > 49 && cents < 55)
    {
        nickels = 10;
    }
    if (cents > 54 && cents < 60)
    {
        nickels = 11;
    }
    if (cents > 59 && cents < 65)
    {
        nickels = 12;
    }
    if (cents > 64 && cents < 70)
    {
        nickels = 13;
    }
    if (cents > 69 && cents < 75)
    {
        nickels = 14;
    }
    if (cents > 74 && cents < 80)
    {
        nickels = 15;
    }
    if (cents > 79 && cents < 85)
    {
        nickels = 16;
    }
    if (cents > 84 && cents < 90)
    {
        nickels = 17;
    }
    if (cents > 89 && cents < 95)
    {
        nickels = 18;
    }
    if (cents > 94 && cents < 100)
    {
        nickels = 19;
    }
    if (cents > 99 && cents < 105)
    {
        nickels = 20;
    }
//    printf("number of nickels = %i\n", nickels);
    return nickels;
}

int calculate_pennies(int cents)
{
//  Calculates number of pennies needed
    int pennies;
    if (cents < 5)
    {
        pennies = cents;
    }
    else
    {
        pennies = cents;
    }

//    printf("number of pennies = %i\n", pennies);
    return pennies;
}
//-----------------------------------------
//if (cents > 4 && cents < 10)
//    {
//        nickels = 1;
//    }
//    if (cents > 14 && cents < 20)
//    {
//        nickels = 1;
//    }
//    if (cents > 29 && cents < 35)
//    {
//        nickels = 1;
//    }
//    if (cents > 39 && cents < 45)
//    {
//        nickels = 1;
//    }
//    if (cents > 54 && cents < 60)
//    {
//        nickels = 1;
//    }
//    if (cents > 64 && cents < 70)
//    {
//        nickels = 1;
//    }
//    if (cents > 89 && cents < 95)
//    {
//        nickels = 1;
//    }