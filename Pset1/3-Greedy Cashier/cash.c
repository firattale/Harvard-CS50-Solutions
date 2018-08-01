#include <stdio.h>
#include <cs50.h>
#include <math.h>

//Greedy Cashier Program
int main(void)
{
    //First we should get a float value and it should be positive!
    float n;
    do
    {
        n = get_float("How much change do you need: ");
    }

    while (n < 0);
    //we have to round it and change to cents by dividing it 100.
    int x = round(n * 100.00);
    //b is the counter
    int b = 0;
    //counting how many 25 cents are we going to have.
    while (x >= 25)

    {
        b++;
        x = x - 25;
    }
    //counting how many 10 cents are we going to have.

    while (x >= 10)

    {
        b++;
        x = x - 10;
    }
    //counting how many 5 cents are we going to have.

    while (x >= 5)

    {
        b++;
        x = x - 5;
    }
    //counting how many 1 cents are we going to have.

    while (x >= 1)

    {
        b++;
        x = x - 1;
    }
    //Lastly we are printing the counter number
    printf("%i\n", b);
}