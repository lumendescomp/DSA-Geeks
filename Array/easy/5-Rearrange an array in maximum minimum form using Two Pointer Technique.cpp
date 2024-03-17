/* Time Complexity: O(N), Iterating over the array of size N 2 times.
Auxiliary Space: O(N), since N extra space has been taken.*/

#include <bits/stdc++.h> 
using namespace std; 
  
// Prints max at first position, min at second position 
// second max at third position, second min at fourth 
// position and so on. 
void rearrange(int arr[], int n) 
{ 
    // Auxiliary array to hold modified array 
    int temp[n]; 
  
    // Indexes of smallest and largest elements 
    // from remaining array. 
    int small = 0, large = n - 1; 
  
    // To indicate whether we need to copy remaining 
    // largest or remaining smallest at next position 
    int flag = true; 
  
    // Store result in temp[] 
    for (int i = 0; i < n; i++) { 
        if (flag) 
            temp[i] = arr[large--]; 
        else
            temp[i] = arr[small++]; 
  
        flag = !flag; 
    } 
  
    // Copy temp[] to arr[] 
    for (int i = 0; i < n; i++) 
        arr[i] = temp[i]; 
} 

/* Time Complexity: O(n)
Auxiliary Space: O(1), as no extra space is used*/
// C++ program to rearrange an array in minimum
// maximum form
#include <bits/stdc++.h>
using namespace std;
 
// Prints max at first position, min at second position
// second max at third position, second min at fourth
// position and so on.
void rearrange(int arr[], int n)
{
    // initialize index of first minimum and first
    // maximum element
    int max_idx = n - 1, min_idx = 0;
 
    // store maximum element of array
    int max_elem = arr[n - 1] + 1;
 
    // traverse array elements
    for (int i = 0; i < n; i++) {
        // at even index : we have to put maximum element
        if (i % 2 == 0) {
            arr[i] += (arr[max_idx] % max_elem) * max_elem;
            max_idx--;
        }
 
        // at odd index : we have to put minimum element
        else {
            arr[i] += (arr[min_idx] % max_elem) * max_elem;
            min_idx++;
        }
    }
 
    // array elements back to it's original form
    for (int i = 0; i < n; i++)
        arr[i] = arr[i] / max_elem;
}

