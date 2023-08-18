// Practice working with structs
// Practice applying sorting algorithms

#include <cs50.h>
#include <stdio.h>
#include <string.h>


#define NUM_CITIES 10

typedef struct
{
    string city;
    int temp;
}
avg_temp;

avg_temp temps[NUM_CITIES];

void sort_cities(void);

int main(void)
{
    temps[0].city = "Austin";
    temps[0].temp = 97;

    temps[1].city = "Boston";
    temps[1].temp = 82;

    temps[2].city = "Chicago";
    temps[2].temp = 85;

    temps[3].city = "Denver";
    temps[3].temp = 90;

    temps[4].city = "Las Vegas";
    temps[4].temp = 105;

    temps[5].city = "Los Angeles";
    temps[5].temp = 82;

    temps[6].city = "Miami";
    temps[6].temp = 97;

    temps[7].city = "New York";
    temps[7].temp = 85;

    temps[8].city = "Phoenix";
    temps[8].temp = 107;

    temps[9].city = "San Francisco";
    temps[9].temp = 66;

    sort_cities();

    printf("\nAverage July Temperatures by City\n\n");

    for (int i = 0; i < NUM_CITIES; i++)
    {
        printf("%s: %i\n", temps[i].city, temps[i].temp);
    }
}

//..................................Sort cities by temperature in descending order
void sort_cities(void)
{
//..................................assume that first element is smallest
        int smalltemp = temps[0].temp;
        string smallcity = temps[0].city;
        int len = (NUM_CITIES);
        for ( int i = 0; i < len; i++ )
        {
            if ( smalltemp > temps[i].temp )
            {
                smalltemp = temps[i].temp;
            }
            for (int j = i+1; j < len; j++)
            {
                if (temps[i].temp < temps[j].temp)
                {
                    smalltemp = temps[i].temp;
                    smallcity = temps[i].city;
                    temps[i].temp = temps[j].temp;
                    temps[i].city = temps[j].city;
                    temps[j].temp = smalltemp;
                    temps[j].city = smallcity;
                }
            }
        }
}
