//Given an array arr[] of N elements, sort the array according to the following relations:  
//arr[i] >= arr[i – 1], if i is even, ∀ 1 <= i < N
//arr[i] <= arr[i – 1], if i is odd, ∀ 1 <= i < N

/* 
Time Complexity: O(N * log N)
Auxiliary Space: O(N)
*/
void assign(int arr[], int N)
{
    // Sort the array
    sort(arr, arr + N);
 
    int ans[N];
    int ptr1 = 0, ptr2 = N - 1;
    for (int i = 0; i < N; i++) {
        // Assign even indexes with maximum elements
        if (i % 2 == 0)
            ans[i] = arr[ptr2--];
        // Assign odd indexes with remaining elements
        else
            ans[i] = arr[ptr1++];
    }
 
    // Print result
    for (int i = 0; i < N; i++)
        cout << ans[i] << " ";
}
/* 
Time Complexity: O(N)
Auxiliary Space: O(1)
*/
void rearrange(int arr[], int N)
{
    for (int i = 0; i < N; i += 2) {
          // Compare it with the previous element
        if (i > 0 && arr[i - 1] > arr[i])
            swap(arr[i - 1], arr[i]);
         
          // Compare it with the next element
        if (i < N - 1 && arr[i + 1] > arr[i])
            swap(arr[i + 1], arr[i]);
    }
}
