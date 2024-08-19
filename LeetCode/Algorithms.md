# Sieve of Eratosthenes

The Sieve of Eratosthenes is an ancient algorithm used to find all prime numbers up to a specified integer. It is named after the Greek mathematician Eratosthenes and is highly efficient for finding primes.

## How It Works

The algorithm works by iteratively marking the multiples of each prime number starting from 2. Here's a step-by-step explanation:

1. **Create a list of consecutive integers** from 2 to the desired maximum number, `n`. For example, if `n = 30`, the list would be:

    ```
    2, 3, 4, 5, 6, 7, 8, ..., 29, 30
    ```

2. **Start with the first number in the list (2)**. This number is prime, so it is kept.

3. **Mark all multiples of this number as composite** (i.e., not prime). In our example, all multiples of 2 greater than 2 itself (4, 6, 8, 10, ...) are marked:
    ```
    2, 3, X, 5, X, 7, X, 9, ..., 29, X
    ```

4. **Move to the next unmarked number** in the list (3 in this case) and repeat the process. Mark all multiples of 3 as composite:

    ```
    2, 3, X, 5, X, 7, X, X, ..., 29, X
    ```

5. **Continue the process** with the next unmarked number (5, then 7, and so on). For each prime number, mark its multiples as composite.

6. **Stop the process when you reach a number** whose square is greater than `n`. At this point, all remaining unmarked numbers in the list are primes.

```python
def sieve_of_eratosthenes(n):
    # Step 1: Create a list of booleans representing numbers 0 to n, all initialized to True.
    primes = [True] * (n + 1)
    p = 2
    
    # Step 2: Iterate from 2 to the square root of n.
    while (p * p <= n):
        # Step 3: If primes[p] is True, it is a prime number.
        if primes[p] == True:
            # Step 4: Mark all multiples of p as False starting from p^2.
            for i in range(p * p, n + 1, p):
                primes[i] = False
        p += 1
    
    # Step 5: Collect all prime numbers.
    prime_numbers = [p for p in range(2, n + 1) if primes[p]]
    
    return prime_numbers
```
