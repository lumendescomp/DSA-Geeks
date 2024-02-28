/*Time complexity: O(N) 
Auxiliary Space: O(N) */
// Function to rotate array
void rotate(int arr[], int d, int N)
{
    // Storing rotated version of array
    int temp[N];
 
    // Keeping track of the current index
    // of temp[]
    int j = 0;
 
    // Storing the n - d elements of
    // array arr[] to the front of temp[]
    for (int i = d; i < N; i++) {
        temp[j] = arr[i];
        j++;
    }
 
    // Storing the first d elements of array arr[]
    //  into temp
    for (int i = 0; i < d; i++) {
        temp[j] = arr[i];
        j++;
    }
 
    // Copying the elements of temp[] in arr[]
    // to get the final rotated array
    for (int i = 0; i < N; i++) {
        arr[i] = temp[i];
    }
}
/* */
 
/* */