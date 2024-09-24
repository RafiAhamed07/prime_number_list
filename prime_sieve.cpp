#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stddef.h>

// Prime listing function
void func(int s, int n)
{
    bool *prime = (bool *)malloc((n + 1) * sizeof(bool));

    if (prime == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    memset(prime, true, (n + 1) * sizeof(bool));

    // algo
    int p = 2;
    //
    while (p * p <= n)
    {

        if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i = i + p)
            {
                prime[i] = false;
            }
        }
        p++;
    }

    // Open file to save output
    FILE *file = fopen("primes_output.txt", "w"); // File Location changed to "/home/fida/Documents/"
    if (file == NULL)
    {
        printf("Could not open file to save output.\n");
        free(prime);
        return;
    }

    printf("\n*****************************************\n");
    printf(" Prime Numbers Between %d and %d\n", s, n);
    printf("*****************************************\n\n");

    fprintf(file, "*****************************************\n");
    fprintf(file, " Prime Numbers Between %d and %d\n", s, n);
    fprintf(file, "*****************************************\n\n");

    int count = 0;
    for (int i = (s > 2) ? s : 2; i <= n; i++)
    { // Start from max(s, 2)

        // 1-10 ==> 2 ,3,5,7

        if (prime[i])
        {
            printf("%d", i);
            fprintf(file, "%d", i); // Save to file
            count++;
            if (i < n && count % 10 != 0)
            {
                printf(" | ");
                fprintf(file, " | ");
            }
            else if (count % 10 == 0)
            {
                printf("\n");
                fprintf(file, "\n");
            }
        }
    }
    printf("\n\n");

    printf("*****************************************\n");
    printf(" Total Primes Found: %d\n", count);
    printf("*****************************************\n");

    fprintf(file, "\n*****************************************\n");
    fprintf(file, " Total Primes Found: %d\n", count);
    fprintf(file, "*****************************************\n");

    fclose(file);

    free(prime);
}

// Main function
int main()
{
    int s, n;
    printf("=========================================================================\n");
    printf("=          Hello, Welcome to the Sieve of Eratosthenes                 ==\n");
    printf("=========================================================================\n");
    printf("= Memory Limit Instructions:                                            =\n");
    printf("=   - With 4GB of RAM: You can enter numbers up to 500,000,000 for n.   =\n");
    printf("=   - With 8GB of RAM: You can enter numbers up to 1,000,000,000 for n. =\n");
    printf("=========================================================================\n");

    printf("Please enter the range of numbers (s and n) you want to find prime numbers between: ");
    scanf("%d", &s);
    scanf("%d", &n);

    if (s > n)
    {
        printf("Invalid range. Make sure s >= 2 and s <= n.\n");
    }
    else
    {
        func(s, n);
        printf("\nThe prime numbers between %d and %d have been saved to 'primes_output.txt'.\n", s, n);
    }

    return 0;
}
