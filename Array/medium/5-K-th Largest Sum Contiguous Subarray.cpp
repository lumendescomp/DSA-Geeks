/*
Time Complexity: O(N2 log K) 
Auxiliary Space: O(N), but this can be reduced to O(K) for min-heap and we can store the prefix sum array in the input array itself as it is of no use.
*/
// ---------------------CODE-----------------------
int kthLargestSum(int arr[], int N, int K)
{
    // array to store prefix sums
    int sum[N + 1];
    sum[0] = 0;
    sum[1] = arr[0];
    for (int i = 2; i <= N; i++)
        sum[i] = sum[i - 1] + arr[i - 1];
 
    // priority_queue of min heap
    priority_queue<int, vector<int>, greater<int> > Q;
 
    // loop to calculate the contiguous subarray
    // sum position-wise
    for (int i = 1; i <= N; i++) {
 
        // loop to traverse all positions that
        // form contiguous subarray
        for (int j = i; j <= N; j++) {
            // calculates the contiguous subarray
            // sum from j to i index
            int x = sum[j] - sum[i - 1];
 
            // if queue has less than k elements,
            // then simply push it
            if (Q.size() < K)
                Q.push(x);
 
            else {
                // it the min heap has equal to
                // k elements then just check
                // if the largest kth element is
                // smaller than x then insert
                // else its of no use
                if (Q.top() < x) {
                    Q.pop();
                    Q.push(x);
                }
            }
        }
    }
 
    // the top element will be then kth
    // largest element
    return Q.top();
}

/*
Time Complexity: O(n^2 log n) ,The time complexity of the above code for the Prefix Sum and Sorting approach is O(n^2logn), where n is the size of the input array. This is due to the nested loop used to calculate all possible subarray sums and the sort() function used to sort the vector of subarray sums.

Auxiliary Space: O(n^2), The auxiliary space complexity of the above code is O(n). This is due to the creation of the prefix sum array(O(n)) and the vector to store all possible subarray sums(O(n^2))
*/
// ---------------------CODE-----------------------
int kthLargestSum(vector<int>& arr, int k)
{
    int n = arr.size();
 
    // Create a prefix sum array.
    vector<int> prefixSum(n + 1);
    prefixSum[0] = 0;
    for (int i = 1; i <= n; i++) {
        prefixSum[i] = prefixSum[i - 1] + arr[i - 1];
    }
 
    // Create a vector to store all possible subarray sums.
    vector<int> subarraySums;
    for (int i = 0; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            subarraySums.push_back(prefixSum[j]
                                   - prefixSum[i]);
        }
    }
 
    // Sort the subarray sums in decreasing order.
    sort(subarraySums.begin(), subarraySums.end(),
         greater<int>());
 
    // Return the K-th largest sum of contiguous subarray.
    return subarraySums[k - 1];
}
