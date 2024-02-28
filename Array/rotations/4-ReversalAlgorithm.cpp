/* Time Complexity: O(N)
Auxiliary Space: O(1)*/
#include <bits/stdc++.h>
using namespace std;
// Function to rotate an array by k elements to the left
void rotateArray(vector<int>& arr, int d)
{
    // Find the size of the array
    int n = arr.size();
 
    // Mod k with the size of the array
    // To handle the case where k is greater than the size
    // of the array
    d %= n;
 
    // Reverse the first k elements
    reverse(arr.begin(), arr.begin() + d);
 
    // Reverse the remaining n-k elements
    reverse(arr.begin() + d, arr.end());
 
    // Reverse the entire array
    reverse(arr.begin(), arr.end());
}
/* */
 
/* */