#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

float calc_grade(float letters, float sentances, float words);

int main(void)
{
    string text = get_string("Text: ");

//    int letters = phrase_eval(text);
//    int sentances = phrase_eval(text);
//    int words = phrase_eval(text);

    int len = strlen(text);
    float letters = 0;
    float sentances = 0;
    float words = 1;
    char (x);

    for (int i = 0; i < len; i++)
    {
        x = text[i];
        if (isalpha(x))
        {
            letters ++;
        }

        if (x == 46 || x == 33 || x == 63)
        {
            sentances++;
        }
        else if (x == ' ')
        {
            words++;
        }
    }
//    printf("letters = %.0f\n", letters);
//    printf("words = %.0f\n", words);
//    printf("sentances = %.0f\n", sentances);


    float num_letters = calc_grade(letters, sentances, words);
//    printf("grade %i\n", int grade);
    if (num_letters < 1)
    {
        num_letters = 1;
        printf("Before Grade %.0f\n", (num_letters));
    }
    else if (num_letters >= 16)
    {
        num_letters = 16;
        printf("Grade %.0f", num_letters);
        printf("+\n");
    }
    else
    {
        printf("Grade %.0f\n", num_letters);
    }
}
//  function to calculate grade level
float calc_grade(float letters, float sentances, float words)

{
    float grade = 0.0588 * (letters / words * 100) - 0.296 * (sentances / words * 100) - 15.8
    return grade;
}