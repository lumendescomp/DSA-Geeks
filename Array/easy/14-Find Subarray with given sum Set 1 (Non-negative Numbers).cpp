/*
Não consegui pensar em nada melhor que O(n²).
Technique: Sliding Window
Time Complexity: O(N)
Auxiliary Space: O(1). Since no extra space has been taken.
*/
// ---------------------CODE-----------------------
int subArraySum(int arr[], int n, int sum)
{
    /* Initialize currentSum as value of
    first element and starting point as 0 */
    int currentSum = arr[0], start = 0, i;
 
    /* Add elements one by one to currentSum and
    if the currentSum exceeds the sum,
    then remove starting element */
    for (i = 1; i <= n; i++) {
        // If currentSum exceeds the sum,
        // then remove the starting elements
        while (currentSum > sum && start < i - 1) {
            currentSum = currentSum - arr[start];
            start++;
        }
 
        // If currentSum becomes equal to sum,
        // then return true
        if (currentSum == sum) {
            cout << "Sum found between indexes " << start
                 << " and " << i - 1;
            return 1;
        }
 
        // Add this element to currentSum
        if (i < n)
            currentSum = currentSum + arr[i];
    }
 
    // If we reach here, then no subarray
    cout << "No subarray found";
    return 0;
}

