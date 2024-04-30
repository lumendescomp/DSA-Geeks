/*
Time Complexity: O(N)
Auxiliary Space: O(1)
*/
// ---------------------CODE-----------------------
int subArraySum(int arr[], int n, int sum)
{
    int currentSum = arr[0], start = 0, i;
    for (i = 1; i <= n; i++) {
        while (currentSum > sum && start < i - 1) {
            currentSum = currentSum - arr[start];
            start++;
        }
 
        if (currentSum == sum) {
            cout << "Sum found between indexes " << start
                 << " and " << i - 1;
            return 1;
        }

        if (i < n)
            currentSum = currentSum + arr[i];
    }
 
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

//Handles negative numbers => https://www.geeksforgeeks.org/find-subarray-with-given-sum-in-array-of-integers/

/*
Time complexity: O(N). If hashing is performed with the help of an array, then this is the time complexity. In case the elements cannot be hashed in an array a hash map can also be used as shown in the above code.
Auxiliary space: O(N). As a HashMap is needed, this takes linear space.
*/
// ---------------------CODE-----------------------
void subArraySum(int arr[], int n, int sum)
{
	// create an empty map
	unordered_map<int, int> map;

	int curr_sum = 0;

	for (int i = 0; i < n; i++) {
		curr_sum = curr_sum + arr[i];

		if (curr_sum == sum) {
			cout << "Sum found between indexes " << 0
				<< " to " << i << endl;
			return;
		}

		if (map.find(curr_sum - sum) != map.end()) {
			cout << "Sum found between indexes "
				<< map[curr_sum - sum] + 1 << " to " << i
				<< endl;
			return;
		}

		map[curr_sum] = i;
	}

	cout << "No subarray with given sum exists";
}
