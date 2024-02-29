/*A subsequence is a sequence that can be derived from another sequence by removing zero or more elements, without changing the order of the remaining elements.
Time Complexity: 0(n*(2^n))
Space Complexity: 0(1) */
    
/*  C++ code to generate all possible subsequences.
    Time Complexity O(n * 2^n) */
#include<bits/stdc++.h>
using namespace std;
 
void printSubsequences(int arr[], int n)
{
    /* Number of subsequences is (2**n -1)*/
    unsigned int opsize = pow(2, n);
 
    /* Run from counter 000..1 to 111..1*/
    for (int counter = 1; counter < opsize; counter++)
    {
        for (int j = 0; j < n; j++)
        {
            /* Check if jth bit in the counter is set
                If set then print jth element from arr[] */
            if (counter & (1<<j))
                cout << arr[j] << " ";
        }
        cout << endl;
    }
}
/* */
 
/* */