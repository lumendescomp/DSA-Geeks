/*
Não consegui pensar em nada melhor que O(n²).
Technique: Sliding Window
Time Complexity: O(N)
Auxiliary Space: O(1). Since no extra space has been taken.
*/
// ---------------------CODE-----------------------
int subArraySum(int arr[], int n, int sum)
{
    /* Initialize currentSum as value of
    first element and starting point as 0 */
    int currentSum = arr[0], start = 0, i;
 
    /* Add elements one by one to currentSum and
    if the currentSum exceeds the sum,
    then remove starting element */
    for (i = 1; i <= n; i++) {
        // If currentSum exceeds the sum,
        // then remove the starting elements
        while (currentSum > sum && start < i - 1) {
            currentSum = currentSum - arr[start];
            start++;
        }
 
        // If currentSum becomes equal to sum,
        // then return true
        if (currentSum == sum) {
            cout << "Sum found between indexes " << start
                 << " and " << i - 1;
            return 1;
        }
 
        // Add this element to currentSum
        if (i < n)
            currentSum = currentSum + arr[i];
    }
 
    // If we reach here, then no subarray
    cout << "No subarray found";
    return 0;
}

/* Dynamic Programming
Time Complexity: O(N)
Auxiliary Space: O(N) 
*/
// ---------------------CODE-----------------------
#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<int> find_subarray_with_given_sum(const std::vector<int>& arr, int sum)
{
    std::unordered_map<int, int> map;
    int curr_sum = 0;
    for (int i = 0; i < arr.size(); i++) {
        curr_sum += arr[i];
        if (curr_sum == sum) {
            return std::vector<int>({0, i});
        }
        if (map.count(curr_sum - sum)) {
            return std::vector<int>({map[curr_sum - sum] + 1, i});
        }
        map[curr_sum] = i;
    }
    return {};
}

int main()
{
    std::vector<int> arr = {15, 2, 4, 8, 5, 10, 23};
    int target_sum = 21;

    std::vector<int> subarray = find_subarray_with_given_sum(arr, target_sum);

    if (subarray.empty()) {
        std::cout << "No subarray with sum " << target_sum << " found." << std::endl;
    } else {
        std::cout << "Sum found between indexes " << subarray[0] << " and " << subarray[1] << std::endl;
    }

    return 0;
}


/*

*/
// ---------------------CODE-----------------------



//Handles negative numbers => https://www.geeksforgeeks.org/find-subarray-with-given-sum-in-array-of-integers/

/*
Time complexity: O(N). If hashing is performed with the help of an array, then this is the time complexity. In case the elements cannot be hashed in an array a hash map can also be used as shown in the above code.
Auxiliary space: O(N). As a HashMap is needed, this takes linear space.
*/
// ---------------------CODE-----------------------
// C++ program to print subarray with sum as given sum
#include <bits/stdc++.h>
using namespace std;

// Function to print subarray with sum as given sum
void subArraySum(int arr[], int n, int sum)
{
	// create an empty map
	unordered_map<int, int> map;

	// Maintains sum of elements so far
	int curr_sum = 0;

	for (int i = 0; i < n; i++) {
		// add current element to curr_sum
		curr_sum = curr_sum + arr[i];

		// if curr_sum is equal to target sum
		// we found a subarray starting from index 0
		// and ending at index i
		if (curr_sum == sum) {
			cout << "Sum found between indexes " << 0
				<< " to " << i << endl;
			return;
		}

		// If curr_sum - sum already exists in map
		// we have found a subarray with target sum
		if (map.find(curr_sum - sum) != map.end()) {
			cout << "Sum found between indexes "
				<< map[curr_sum - sum] + 1 << " to " << i
				<< endl;
			return;
		}

		map[curr_sum] = i;
	}

	// If we reach here, then no subarray exists
	cout << "No subarray with given sum exists";
}

// Driver code
int main()
{
	int arr[] = { 10, 2, -2, -20, 10 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int sum = -10;

	// Function call
	subArraySum(arr, n, sum);

	return 0;
}


/*

*/
// ---------------------CODE-----------------------

