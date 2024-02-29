/* Time Complexity: O(n), where n is the size of input array.
Auxiliary space: O(1), as no extra space is required.*/
    
// C++ program to find the second largest element
 
#include <iostream>
using namespace std;
 
// returns the index of second largest
// if second largest didn't exist return -1
int secondLargest(int arr[], int n) {
    int first = 0, second = -1;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[first]) {
            second = first;
            first = i;
        }
        else if (arr[i] < arr[first]) {
            if (second == -1 || arr[second] < arr[i])
                second = i;
        }
    }
    return second;
}
/* */
 
/* */