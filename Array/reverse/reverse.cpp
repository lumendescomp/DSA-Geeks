/* Time Complexity: O(n)
Copying elements to a new array is a linear operation.
Auxiliary Space Complexity: O(n)
Additional space is used to store the new array.*/
  
#include <iostream>
using namespace std;
 
void reverseArrayExtraArray(int arr[], int s) {
    vector<int> reversedArr(s); 
    for (int i = 0; i < s; i++) {
        reversedArr[i] = arr[s - i - 1];
    }
 
    // Print reversed array
    cout << "Reversed Array: ";
    for (int i = 0; i < s; i++) {
        std::cout << reversedArr[i] << " ";
    }
}
int main() {
    int originalArr[] = {1, 2, 3, 4, 5};
    int size = sizeof(originalArr) / sizeof(originalArr[0]);
     
    reverseArrayExtraArray(originalArr, size);
}

/*Time Complexity: O(n)
The loop runs through half of the array, so it’s linear with respect to the array size.
Auxiliary Space Complexity: O(1)
In-place reversal, meaning it doesn’t use additional space. */
   
// Iterative C++ program to reverse an array 
#include <bits/stdc++.h> 
using namespace std; 
 
/* Function to reverse arr[] from start to end*/
void rvereseArray(int arr[], int start, int end) 
{ 
    while (start < end) 
    { 
        int temp = arr[start]; 
        arr[start] = arr[end]; 
        arr[end] = temp; 
        start++; 
        end--; 
    } 
} 



/* Time Complexity: O(n). The recursion goes through each element once, so it’s linear.
Auxiliary Space Complexity: O(n) for non in-place, O(log n) for in-place (due to recursion stack)*/
#include <bits/stdc++.h> 
using namespace std; 
 
/* Function to reverse arr[] from start to end*/
void rvereseArray(int arr[], int start, int end) 
{ 
    if (start >= end) 
    return; 
     
    int temp = arr[start]; 
    arr[start] = arr[end]; 
    arr[end] = temp; 
     
    // Recursive Function calling 
    rvereseArray(arr, start + 1, end - 1); 
}  




/*Time Complexity: O(n)
Pushing and popping each element onto/from the stack requires linear time.
Auxiliary Space Complexity: O(n)
Additional space is used to store the stack. */
#include <iostream>
#include <stack>
#include <vector>
 
void reverseArrayUsingStack(int arr[], int size) {
    std::stack<int> stack;
 
    // Push elements onto the stack
    for (int i = 0; i < size; i++) {
        stack.push(arr[i]);
    }
 
    // Pop elements from the stack to reverse the array
    for (int i = 0; i < size; i++) {
        arr[i] = stack.top();
        stack.pop();
    }
}
/* */
