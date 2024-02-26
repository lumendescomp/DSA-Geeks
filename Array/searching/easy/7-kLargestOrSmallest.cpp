//Time complexity: O(n * log (mx-mn)), where mn be minimum and mx be maximum element of array.
//Auxiliary Space: O(1)
int findKthLargest(int arr[], int n, int k)
{
	int low = INT_MAX, high = INT_MIN;

	// Find the minimum and maximum elements in the array
	for (int i = 0; i < n; i++) {
		low = min(low, arr[i]);
		high = max(high, arr[i]);
	}

	// Perform binary search on the range of elements
	// between low and high
	while (low <= high) {
		int mid = low + (high - low) / 2;
		int count = 0;

		// Count the number of elements greater than mid in
		// the array
		for (int i = 0; i < n; i++) {
			if (arr[i] > mid) {
				count++;
			}
		}

		// If there are at least K elements greater than
		// mid, search the right half
		if (count >= k) {
			low = mid + 1;
		}
		// Otherwise, search the left half
		else {
			high = mid - 1;
		}
	}

	// Return the Kth largest element
	return high;
}

//Time Complexity: O(N²) in worst case(O(N) on average).
//Auxiliary Space: O(N)
void KthLargest(int arr[], int l, int r, int K, int N)
{

	// Partition the array around last element and get
	// position of pivot element in sorted array
	int pos = partition(arr, l, r);

	// If position is same as k
	if (pos - l == K - 1)
		return;

	// If position is less, recur
	// for right subarray
	else if (pos - l < K - 1)
		return KthLargest(arr, pos + 1, r, K - pos + l - 1,
						N);

	// Else recur for left subarray
	else
		return KthLargest(arr, l, pos - 1, K, N);
}
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
int partition(int arr[], int l, int r)
{
	int x = arr[r], i = l;
	for (int j = l; j <= r - 1; j++) {
		if (arr[j] <= x) {
			swap(&arr[i], &arr[j]);
			i++;
		}
	}

	swap(&arr[i], &arr[r]);
	return i;
}

//Time Complexity: O(N * log(K))
//Auxiliary Space: O(K)
void kLargest(vector<int>& v, int N, int K)
{
	// Implementation using
	// a Priority Queue
	priority_queue<int, vector<int>, greater<int> > pq;

	for (int i = 0; i < N; ++i) {

		// Insert elements into
		// the priority queue
		pq.push(v[i]);

		// If size of the priority
		// queue exceeds k
		if (pq.size() > K) {
			pq.pop();
		}
	}

	// Print the k largest element
	while (!pq.empty()) {
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
}

