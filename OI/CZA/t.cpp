// C program to find multiplicative modulo inverse using
// Extended Euclid algorithm.
#include <stdio.h>
#include <iostream>

long long gcdExtended(long long a, long long b, long long* x, long long* y);

// Function to find modulo inverse of a
void modInverse(long long A, long long M)
{
	long long x, y;
	long long g = gcdExtended(A, M, &x, &y);
	if (g != 1)
		printf("Inverse doesn't exist");
	else {
		// m is added to handle negative x
		long long res = (x % M + M) % M;
		std::cout << ("Modular multiplicative inverse is ") << ( res);
	}
}

// C function for extended Euclidean Algorithm
long long gcdExtended(long long a, long long b, long long* x, long long* y)
{
	// Base Case
	if (a == 0) {
		*x = 0, *y = 1;
		return b;
	}

	long long x1, y1; // To store results of recursive call
	long long gcd = gcdExtended(b % a, a, &x1, &y1);

	// Update x and y using results of recursive
	// call
	*x = y1 - (b / a) * x1;
	*y = x1;

	return gcd;
}

// Driver Code
int main()
{
	long long A = 31, M = 1313131345364123;

	// Function call
	modInverse(A, M);
	return 0;
}

