#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // check if user gives 2 arguments otherwise give error
    if (argc != 2)
    {
        printf("Error\n");
        return 1;
    }
    else
    {
        string k = argv[1];
        // check if the key includes only string
        for (int i = 0, n = strlen(k); i < n ; i++)
        {
            if (!isalpha(k[i]))
            {
                printf("Error\n");
                return 1;
            }
        }
    }

// convert user's key into lowercase
    string k =  argv[1];
    for (int i = 0; k[i]; i++)
    {
        k[i] = tolower(k[i]);
    }

    string p = get_string("Plaintext: ");
    printf("ciphertext: ");

// iterating over each letter in plaintext
    for (int i = 0, j = strlen(k), c = 0, n = strlen(p); i < n; i++)
    {
// check if letter is lowercase and valid and
        if (isalpha(p[i]) && islower(p[i]))
        {
// int c is counting only letters so we can escape non-letter things to effect our key index.
            // kIndex is coming back to 0 when we come to end of keyword.
            int kIndex = c % j;
            int kAlphabetical = k[kIndex] - 97;
            int pAlphabetical = p[i] - 97;
            p[i] = 97 + ((kAlphabetical + pAlphabetical) % 26);
            printf("%c", p[i]);
            c++;
        }
// check if letter is uppercase and valid
        else if (isalpha(p[i]) && isupper(p[i]))
        {
            int kIndex = c % j;
            int kAlphabetical = k[kIndex] - 97;
            int pAlphabetical = p[i] - 65;
            p[i] = 65 + ((kAlphabetical + pAlphabetical) % 26);
            printf("%c", p[i]);
            c++;
        }
        else
        {
            printf("%c", p[i]);
        }
    }
    printf("\n");

}
