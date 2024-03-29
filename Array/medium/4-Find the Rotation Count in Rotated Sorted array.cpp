/*
Time Complexity: O(log N) 
Auxiliary Space: O(log N)  [this is the space of recursion stack]
*/
// ---------------------CODE-----------------------
int countRotations(int arr[], int low, int high) 
{ 
    // This condition is needed to handle the case 
    // when the array is not rotated at all 
    if (high < low) 
        return 0; 
  
    // If there is only one element left 
    if (high == low) 
        return low; 
  
    // Find mid 
    int mid = low + (high - low) / 2; /*(low + high)/2;*/
  
    // Check if element (mid+1) is minimum element. 
    // Consider the cases like {3, 4, 5, 1, 2} 
    if (mid < high && arr[mid + 1] < arr[mid]) 
        return (mid + 1); 
  
    // Check if mid itself is minimum element 
    if (mid > low && arr[mid] < arr[mid - 1]) 
        return mid; 
  
    // Decide whether we need to go to left half or 
    // right half 
    if (arr[high] > arr[mid]) 
        return countRotations(arr, low, mid - 1); 
  
    return countRotations(arr, mid + 1, high); 
} 

/*
Time Complexity: O(log N)
Auxiliary Space: O(1), since no extra space has been taken.
*/
// ---------------------CODE-----------------------
int countRotations(int arr[], int n) 
{ 
    int low = 0, high = n - 1; 
    if (arr[low] <= arr[high]) 
        return 0; 
    /*returns 0 if array is already sorted*/
    while (low <= high) { 
  
        // if first element is mid or 
        // last element is mid 
        // then simply use modulo so it 
        // never goes out of bound. 
        int mid = low + (high - low) / 2; 
        int prev = (mid - 1 + n) % n; 
        int next = (mid + 1) % n; 
  
        if (arr[mid] <= arr[prev] && arr[mid] <= arr[next]) 
            return mid; 
        else if (arr[mid] <= arr[high]) 
            high = mid - 1; 
        else if (arr[mid] >= arr[0]) 
            low = mid + 1; 
    } 
    return 0; 
} 
