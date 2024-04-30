//Given an array of random numbers, Push all the zero’s of a given array to the end of the array. For example, if the given arrays is {1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0}, it should be changed to {1, 9, 8, 4, 2, 7, 6, 0, 0, 0, 0}. The order of all other elements should be same. Expected time complexity is O(n) and extra space is O(1).

/*
Time Complexity: O(n) where n is the size of elements of the input array.
Auxiliary Space: O(1) 
*/
void push_zeros_to_end(vector<int>& arr) 
{ 
  std::stable_partition(arr.begin(), 
            arr.end(), 
            [](int n) { return n != 0; }); 
} 
/*
Time Complexity: O(N), 
Auxiliary Space: O(1)  */
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
/* 
Time complexity: O(N), 
Auxiliary space: O(1).
*/
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