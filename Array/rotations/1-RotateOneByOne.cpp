/* LEFT ROTATION 
Time Complexity: O(N * d)
Auxiliary Space: O(1)*/
/*Function to left rotate arr[] of size n by d*/
void rotate(int arr[], int d, int n)
{
    int p = 1;
    while (p <= d) {
        int last = arr[0];
        for (int i = 0; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        arr[n - 1] = last;
        p++;
    }
}

