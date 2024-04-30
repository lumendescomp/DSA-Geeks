//Given an array with N distinct elements, convert the given array to a form where all elements are in the range from 0 to N-1. The order of elements is the same, i.e., 0 is placed in the place of the smallest element, 1 is placed for the second smallest element, … N-1 is placed for the largest element. 
/*
Time complexity: O(N * log N)
Auxiliary Space: O(N)
*/

// ---------------------CODE-----------------------
void convert(int arr[], int n)
{
	int temp[n];
	memcpy(temp, arr, n*sizeof(int));
	sort(temp, temp + n);
	unordered_map<int, int> umap;
	int val = 0;
	for (int i = 0; i < n; i++)
		umap[temp[i]] = val++;
	for (int i = 0; i < n; i++)
		arr[i] = umap[arr[i]];
}


/*
Time Complexity: O(N * log N) as insertion of N elements in priority_queue takes N*logN time. Here, N is size of the input array.

Space Complexity: O(N) as priority_queue pq and temp array has been created.
*/
// ---------------------CODE-----------------------
void convert(int arr[], int n) {
    int temp[n];
    memcpy(temp, arr, n*sizeof(int));
     
      priority_queue<int, vector<int>, greater<int>> pq;
   
      for( int i = 0; i < n; i++)
      pq.push( arr[i] );
       
      int i = 0;
   
      while(!pq.empty()) {
      temp[i++] = pq.top();
      pq.pop();
    }
       
    unordered_map<int, int> umap;
 
    int val = 0;
    for (int i = 0; i < n; i++)
        umap[temp[i]] = val++;
 
    for (int i = 0; i < n; i++)
        arr[i] = umap[arr[i]];
}