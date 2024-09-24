# Prime Number Listing Program (Sieve of Eratosthenes)

## Overview

This C program implements the **Sieve of Eratosthenes** algorithm to find all prime numbers in a given range. It efficiently calculates prime numbers using dynamic memory allocation and saves the result to a text file for further use. The output is displayed in the terminal as well as saved to a file.

## Features

- Fast calculation of primes using the Sieve of Eratosthenes algorithm.
- Handles large ranges up to hundreds of millions of numbers (depending on available RAM).
- Saves results to a specified file in a readable format.

## How to Use

1. Clone the repository:

   ```bash
   git clone <https://github.com/RafiAhamed07/prime_numder_list.git>
   cd <prime_numder_list>
   ```

2. Compile the program:
   ```bash
    gcc prime_sieve.c -o prime_sieve
   ```
3. Run the program:

   ```bash
    ./prime_sieve
   ```
## Output

- The prime numbers between the range you input will be displayed in the terminal.
- The prime numbers will also be saved in a text file named as <b>primes_output.txt</b> on the current directory.


## Memory Considerations
- For systems with 4GB RAM, you can compute primes for numbers up to 500 million.
- For systems with 8GB RAM, you can compute primes for numbers up to 1 billion.

## Error Handling
- If memory allocation fails, the program will terminate with an error message.
- If the file cannot be opened, the program will display an error and exit.

