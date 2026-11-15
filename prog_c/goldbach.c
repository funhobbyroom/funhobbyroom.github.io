/************************************************
 ** goldbach.c checks if a user input number   **
 ** is prime or finds a golbach representation **
 ************************************************/

#include <stdio.h>
#define MAX_NUM 10000000000

// Check if a number is prime

int prime(long long number) 
{
	if (number == 1)	// 1 is not prime
		return 0;

	if (number == 2 || number == 3) // 2 & 3 are primes
		return 1;

	if (!(number%2) || !(number%3)) // Not prime if divided by 2 & 3
		return 0;

	/* Begining from  5 checks the division with  5 & 7 and so on,
	    making jumps of 6, since the other divisors  are covered by 2 & 3 */ 

	for (long long i = 5 ; i*i <= number ; i += 6) 
		if (!(number%i) || !(number%(i+2)))
			return 0;

	return 1;
}

int main()
{

	long long num = 0;
	int ans;
	char choise;

	while (1)
	{
		ans = 0;

		printf("Give me a number: "); 
		ans = scanf("%lld", &num);	// Gets the number to be checked
		
		// Meets or iputs EOF 
		if (ans == EOF) {			
			printf("EOF detected, exiting\n");
			return 0;
		}

		// Did not get an integer
		if (!ans) {
			fprintf(stderr, "Invalid input: expected an integer\n");
			return 1;
		}

		// Input number out of limits
		if (num<0 || num >MAX_NUM) {
			fprintf(stderr, "Number should be in the range [0, 10000000000]\n");
			return 1;
		}

		printf("Choose how to test %lld - ('p' for prime, 'g' for goldbach) ", num);
		ans  = scanf(" %c", &choise); // Gets choise for prime or Goldbach

		// Meets or iputs EOF 
               	if (ans == EOF) {
                        printf("EOF detected, exiting\n");
                        return 0;
                }
		
		// Checks for prime and prints
		if (choise == 'p') { 
			printf("%lld is %sprime\n", num, prime(num)?"":"not ");
		} else if (choise ==  'g') {
			// Checks if number is less than two and odd
			if (num <= 2 || num%2) {
				printf("Goldbach's conjecture is applicable only to even numbers greater than 2!\n");
				continue;
			}
			
			long long fst, snd = 0;
			
			// Finds 2 prime addends of number
			for (fst = 2 ; fst <= num/2 ; fst++) {
				snd = num - fst;
				if (prime(fst) && prime(snd)) {
					printf("%lld = %lld + %lld\n", num, fst, snd);
					break;
				}
			}
		// Choise in not 'p' nor 'g'	
		} else {
			fprintf(stderr, "Invalid choice: expected 'p'or 'g'\n");
			return 1;
		}
		
			
	}

	return 0;
}
