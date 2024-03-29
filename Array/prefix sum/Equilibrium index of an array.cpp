/*
Time Complexity: O(N)
Auxiliary Space: O(N)
*/
// ---------------------CODE-----------------------
// C++ program to find equilibrium index of an array
#include <bits/stdc++.h>
using namespace std;

int equilibrium(int a[], int n)
{
	if (n == 1)
		return (0);
	int forward[n] = { 0 };
	int rev[n] = { 0 };

	// Taking the prefixsum from front end array
//As We Know that in prefixsum from front end the first prefixsum will be equal to first element in the array
//As well as from the back end the first prefixsum will be equal to last element in the array 
forward[0]=a[0];
rev[n-1]=a[n-1];
	for (int i = 1; i < n; i++) {
			forward[i] = forward[i - 1] + a[i];
		
	}

	// Taking the prefixsum from back end of array
	for (int i = n - 2; i >= 0; i--) {
		
			rev[i] = rev[i + 1] + a[i];
	
	}

	// Checking if forward prefix sum
	// is equal to rev prefix
	// sum
	for (int i = 0; i < n; i++) {
		if (forward[i] == rev[i]) {
			return i;
		}
	}
	return -1;

	// If You want all the points
	// of equilibrium create
	// vector and push all equilibrium
	// points in it and
	// return the vector
}

// Driver code
int main()
{
	int arr[] = { -7, 1, 5, 2, -4, 3, 0 };
	int n = sizeof(arr) / sizeof(arr[0]);

	// Function call
	cout << "First Point of equilibrium is at index "
		<< equilibrium(arr, n) << "\n";
	return 0;
}

/*
BETTER BUT NOT PREFIX SUM APPROACH
Time Complexity: O(N)
Auxiliary Space: O(1)
*/
// ---------------------CODE-----------------------
// C++ program to find equilibrium
// index of an array
#include <bits/stdc++.h>
using namespace std;

int equilibrium(int arr[], int n)
{
	int sum = 0; // initialize sum of whole array
	int leftsum = 0; // initialize leftsum

	/* Find sum of the whole array */
	for (int i = 0; i < n; ++i)
		sum += arr[i];

	for (int i = 0; i < n; ++i) {
		sum -= arr[i]; // sum is now right sum for index i

		if (leftsum == sum)
			return i;

		leftsum += arr[i];
	}

	/* If no equilibrium index found, then return 0 */
	return -1;
}

// Driver code
int main()
{
	int arr[] = { -7, 1, 5, 2, -4, 3, 0 };
	int arr_size = sizeof(arr) / sizeof(arr[0]);

	// Function call
	cout << "First equilibrium index is "
		<< equilibrium(arr, arr_size);
	return 0;
}



