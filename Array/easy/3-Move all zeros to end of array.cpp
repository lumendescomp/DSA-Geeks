/*Time Complexity: O(n) where n is the size of elements of the input array.
Auxiliary Space: O(1) */
#include <algorithm> 
#include <iostream> 
#include <vector> 
  
void push_zeros_to_end(std::vector<int>& arr) 
{ 
  std::stable_partition(arr.begin(), 
            arr.end(), 
            [](int n) { return n != 0; }); 
} 
/*Time Complexity: O(N), where N is the size of elements of the input array.
Auxiliary Space: O(1)  */
#include <bits/stdc++.h> 
using namespace std; 
int main() 
{ 
    int A[] = { 5, 6, 0, 4, 6, 0, 9, 0, 8 }; 
    int n = sizeof(A) / sizeof(A[0]); 
    int j = 0; 
    for (int i = 0; i < n; i++) { 
        if (A[i] != 0) { 
            swap(A[j], A[i]); // Partitioning the array 
            j++; 
        } 
    } 
    for (int i = 0; i < n; i++) { 
        cout << A[i] << " "; // Print the array 
    } 
  
    return 0; 
}
/* Time complexity: O(N), where N is the size of elements of the input array.
Auxiliary space: O(1).*/
#include <bits/stdc++.h> 
using namespace std; 
// function to shift zeros 
void move_zeros_to_right(vector<int>& m) 
{ 
    int count = 0; 
      int length=m.size(); 
    for (int i = 0; i < length; i++) { 
        if (m[i] == 0) { 
            count++; 
            // deleting the element from vector 
            m.erase(m.begin() + i); 
              i--; 
              // The length gets decresed after erasing each element 
              length--; 
        } 
    } 
  
    for (int i = 0; i < count; i++) { 
        // inserting the zero into vector 
        m.push_back(0); 
    } 
    cout << "array after shifting zeros to right side: "
         << endl; 
    for (int i = 0; i < m.size(); i++) { 
        // printing desired vector 
        cout << m[i] << " "; 
    } 
} 