/*
Time Complexity: O(n)
Auxiliary Space: O(1)
*/
// ---------------------CODE-----------------------
int findOdd(int arr[], int n)
{
    int res = 0, i;
    for (i = 0; i < n; i++)
        res ^= arr[i];
    return res;
}
