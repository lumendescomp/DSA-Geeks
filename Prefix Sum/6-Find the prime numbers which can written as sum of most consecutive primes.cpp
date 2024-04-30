/*
Given an array of limits. For every limit, find the prime number which can be written as the sum of the most consecutive primes smaller than or equal to limit.
The maximum possible value of a limit is 10^4.


*/
// ---------------------CODE-----------------------
\
// C++ program to find Longest Sum of consecutive
// primes
#include<bits/stdc++.h>
using namespace std;
const int MAX = 10000;

// utility function for sieve of sundaram
void sieveSundaram(vector <int> &primes)
{
	// In general Sieve of Sundaram, produces primes smaller
	// than (2*x + 2) for a number given number x. Since
	// we want primes smaller than MAX, we reduce MAX to half
	// This array is used to separate numbers of the form
	// i+j+2ij from others where 1 <= i <= j
	bool marked[MAX/2 + 1] = {0};

	// Main logic of Sundaram. Mark all numbers which
	// do not generate prime number by doing 2*i+1
	for (int i=1; i<=(sqrt(MAX)-1)/2; i++)
		for (int j=(i*(i+1))<<1; j<=MAX/2; j=j+2*i+1)
			marked[j] = true;

	// Since 2 is a prime number
	primes.push_back(2);

	// Print other primes. Remaining primes are of the
	// form 2*i + 1 such that marked[i] is false.
	for (int i=1; i<=MAX/2; i++)
		if (marked[i] == false)
			primes.push_back(2*i + 1);
}

// function find the prime number which can be written
// as the sum of the most consecutive primes
int LSCPUtil(int limit, vector<int> &prime, long long int sum_prime[])
{
	// To store maximum length of consecutive primes that can
	// sum to a limit
	int max_length = -1;

	// The prime number (or result) that can be represented as
	// sum of maximum number of primes.
	int prime_number = -1;

	// Consider all lengths of consecutive primes below limit.
	for (int i=0; prime[i]<=limit; i++)
	{
		for (int j=0; j<i; j++)
		{
			// if we cross the limit, then break the loop
			if (sum_prime[i] - sum_prime[j] > limit)
				break;

			// sum_prime[i]-sum_prime[j] is prime number or not
			long long int consSum = sum_prime[i] - sum_prime[j];

			// Check if sum of current length of consecutives is
			// prime or not.
			if (binary_search(prime.begin(), prime.end(), consSum))
			{
				// update the length and prime number
				if (max_length < i-j+1)
				{
					max_length = i-j+1;
					prime_number = consSum;
				}
			}
		}
	}

	return prime_number;
}

// Returns the prime number that can written as sum
// of longest chain of consecutive primes.
void LSCP(int arr[], int n)
{
	// Store prime number in vector
	vector<int> primes;
	sieveSundaram(primes);

	long long int sum_prime[primes.size() + 1];

	// Calculate sum of prime numbers and store them
	// in sum_prime array. sum_prime[i] stores sum of
	// prime numbers from primes[0] to primes[i-1]
	sum_prime[0] = 0;
	for (int i = 1 ; i <= primes.size(); i++)
		sum_prime[i] = primes[i-1] + sum_prime[i-1];

	// Process all queries one by one
	for (int i=0; i<n; i++)
	cout << LSCPUtil(arr[i], primes, sum_prime) << " ";
}

// Driver program
int main()
{
	int arr[] = {10, 30, 40, 50, 1000};
	int n = sizeof(arr)/sizeof(arr[0]);
	LSCP(arr, n);
	return 0;
}


/*

*/
// ---------------------CODE-----------------------

