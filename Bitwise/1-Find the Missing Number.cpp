/*
Time Complexity: O(N) 
Auxiliary Space: O(1) 
*/
// ---------------------CODE-----------------------
int getMissingNo(int a[], int n)
{
    // For xor of all the elements in array
    int x1 = a[0];

    // For xor of all the elements from 1 to n+1
    int x2 = 1;

    for (int i = 1; i < n; i++)
        x1 = x1 ^ a[i];

    for (int i = 2; i <= n + 1; i++)
        x2 = x2 ^ i;

    return (x1 ^ x2);
}

/*
Time Complexity: O(N)
Auxiliary Space: O(1)
*/
// ---------------------CODE-----------------------
int getMissingNo(int a[], int n)
{
    // Given the range of elements
    // are 1 more than the size of array
    int N = n + 1;
  
    int total = (N) * (N + 1) / 2;
    for (int i = 0; i < n; i++)
        total -= a[i];
    return total;
}
