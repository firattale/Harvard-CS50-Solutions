#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    // prompt a number from user
    long long int n;
    do
    {
        n = get_long_long("Enter a long long: ");
    }
    while (n < 0 );

    long long int ccnum = n;

    // count how many digits in that number

    int count = 0;
    do
    {
        n = n / 10;
        count++;
    }

    while (n != 0);

    if (!(count == 13 || count == 15 || count == 16))
    {
        printf("INVALID\n");
    }

    int checksum = 0;
    long long int ccnum2 = ccnum;
    int digit;
    int double;

    for (int i = 0; i < count; i++ )
    {

        digit = ccnum2 % 100;
        ccnum2 = ccnum2 / 100;
        double = digit * 2
        if (double  > 10)
        { double = (digit % 10) + 1}
        checksum = checksum + double;
    }

    printf("%lld\n", n);
    printf("%i\n", count);
}