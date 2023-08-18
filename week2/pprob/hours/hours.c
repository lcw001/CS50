#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

float calc_hours(int hours[], int weeks, char output);

int main(void)
{
    int weeks = get_int("Number of weeks taking CS50: ");
    int hours[weeks];

    for (int i = 0; i < weeks; i++)
    {
        hours[i] = get_int("Week %i HW Hours: ", i);
    }

    char output;
    do
    {
        output = toupper(get_char("Enter T for total hours, A for average hours per week: "));
    }
    while (output != 'T' && output != 'A');

    printf("%.1f hours\n", calc_hours(hours, weeks, output));
}

// TODO: complete the calc_hours function
float calc_hours(int hours[], int weeks, char output)
{
    if (output == 'T')
    {
        // calculates total hours
        int sum = 0;
        for (int i = 0; i < weeks; i++)
        {
            sum = sum + hours[i];
        }
        output = sum;
        //  printf("sum = %i\n", sum);
        //  printf("output = %i\n", output);
        return output;
    }
    else
    {
        //  calculates average and returns float
        float sum;
        for (int i = 0; i < weeks; i++)
        {
            sum = sum + hours[i];
        }
        output = sum;
        //  printf("output = %i\n", output);
        //  printf("sum = %f\n", sum);
//      //  printf("output avg = %f\n", output / (float)weeks);
        return output / (float)weeks;
    }
}