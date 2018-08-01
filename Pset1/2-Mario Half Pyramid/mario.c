#include <stdio.h>
#include <cs50.h>

int main(void)
{

    int height;
//Defining height variable
    do
    {
        printf("Give me a number: ");
        height = get_int();
    }
    while (height < 0 || height > 23);
//Defining how many rows, how many places in a row and which characters
    for (int row = 1; row <= height; row++)
    {

        for (int j = 0; j <= height; j++)
        {
            if (height - j <= row)
            {

                printf("#");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}