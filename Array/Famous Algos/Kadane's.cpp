/*
Time Complexity: O(N)
Auxiliary Space: O(1)
*/
// ---------------------CODE-----------------------
int maxSubArraySum(int a[], int size)
{
    int max_so_far = INT_MIN, max_ending_here = 0;

    for (int i = 0; i < size; i++) {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;

        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}

/*
Time Complexity: O(n)
Auxiliary Space: O(1)
*/
// ---------------------CODE-----------------------
void maxSubArraySum2(int a[], int size)
{
    int max_so_far = INT_MIN, max_ending_here = 0,
        start = 0, end = 0, s = 0;

    for (int i = 0; i < size; i++) {
        max_ending_here += a[i];

        if (max_so_far < max_ending_here) {
            max_so_far = max_ending_here;
            start = s;
            end = i;
        }

        if (max_ending_here < 0) {
            max_ending_here = 0;
            s = i + 1;
        }
    }
    cout << "Maximum contiguous sum is " << max_so_far
         << endl;
    cout << "Starting index " << start << endl
         << "Ending index " << end << endl;
}

/*
Time Complexity: O(n)
Auxiliary Space: O(n)
*/
// ---------------------CODE-----------------------
int maxSubArraySum3(int a[], int size)
{
    vector<int> dp(size, 0);
    dp[0] = a[0];
    int ans = dp[0];
    for (int i = 1; i < size; i++) {
        dp[i] = max(a[i], a[i] + dp[i - 1]);
        ans = max(ans, dp[i]);
    }
    cout << ans;
}
