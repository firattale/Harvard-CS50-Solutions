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
        printf("Error");
        return 1;
    }
    else
    {
        // convert user's key into an integer
        string k = argv[1];
        int l = atoi(k);

        string p = get_string("Plaintext: ");
        printf("ciphertext: ");


        for (int i = 0, n = strlen(p); i < n; i++)
        {
            // check if letter is lowercase and valid and iterate it
            if (isalpha(p[i]) && islower(p[i]))
            {
                int t = p[i] - 97;
                p[i] = 97 + ((t + l) % 26);
                printf("%c", p[i]);
            }
            // check if letter is uppercase and valid and iterate it
            else if (isalpha(p[i]) && isupper(p[i]))
            {
                int v = p[i] - 65;
                p[i] = 65 + ((v + l) % 26);
                printf("%c", p[i]);
            }
            else
            {
                printf("%c", p[i]);
            }
        }
        printf("\n");
    }
}