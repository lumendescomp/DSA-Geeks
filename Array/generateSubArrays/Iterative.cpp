/* For an array/string of size n, there are n*(n+1)/2 non-empty subarrays/substrings. */
   
/*  C++ code to generate all possible subarrays/subArrays
    Complexity- O(n^3) */
#include<bits/stdc++.h>
using namespace std;
 
// Prints all subarrays in arr[0..n-1]
void subArray(int arr[], int n)
{
    // Pick starting point
    for (int i=0; i <n; i++)
    {
        // Pick ending point
        for (int j=i; j<n; j++)
        {
            // Print subarray between current starting
            // and ending points
            for (int k=i; k<=j; k++)
                cout << arr[k] << " ";
 
            cout << endl;
        }
    }
}
/* */

/* */
