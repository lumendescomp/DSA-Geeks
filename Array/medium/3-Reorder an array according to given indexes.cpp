/*
Time Complexity: O(n log n)
Auxiliary Space: O(n)
*/
// ---------------------CODE-----------------------
bool comp(const pair<int, int>& v1,
          const pair<int, int>& v2)
{
    // Sort in ascending order of index values
    return v1.second < v2.second;
}
 
// Function to reorder elements of arr[] according to
// index[]
void reorder(int arr[], int index[], int n)
{
    // Create a vector of pairs, where each pair stores the
    // original element (arr[i]) and its corresponding index
    // (index[i])
    vector<pair<int, int> > a(n);
 
    for (int i = 0; i < n; i++) {
        a[i].first = arr[i];
        a[i].second = index[i];
    }
 
    // Sort the vector of pairs based on the second element
    // (index) using the comp() comparator function
    sort(a.begin(), a.end(), comp);
 
    // Copy the sorted elements back to the original arr[]
    for (int i = 0; i < n; i++) {
        arr[i] = a[i].first;
    }
}

/*
Time Complexity: O(n) 
Auxiliary Space: O(n)
*/
// ---------------------CODE-----------------------
void reorder(int arr[], int index[], int n)
{
    int temp[n];
 
    // arr[i] should be present at index[i] index
    for (int i=0; i<n; i++)
        temp[index[i]] = arr[i];
 
    // Copy temp[] to arr[]
    for (int i=0; i<n; i++)
    { 
       arr[i]   = temp[i];
       index[i] = i;
    }
}

/*
Time Complexity: O(n) 
Auxiliary Space: O(1)
*/
// ---------------------CODE-----------------------
void reorder(int arr[], int index[], int n)
{
    // Fix all elements one by one
    for (int i=0; i<n; i++)
    {
        // While index[i] and arr[i] are not fixed
        while (index[i] != i)
        {
            // Store values of the target (or correct) 
            // position before placing arr[i] there
            int  oldTargetI  = index[index[i]];
            char oldTargetE  = arr[index[i]];
 
            // Place arr[i] at its target (or correct)
            // position. Also copy corrected index for
            // new position
            arr[index[i]] = arr[i];
            index[index[i]] = index[i];
 
            // Copy old target values to arr[i] and
            // index[i]
            index[i] = oldTargetI;
            arr[i]   = oldTargetE;
        }
    }
}

/*
Time Complexity: O(N)
Auxiliary Space: O(1)
*/
// ---------------------CODE-----------------------
void rearrange(int arr[], int index[], int n)
{
    int z = findMax(arr, n) + 1;
    for (int i = 0; i < n; i++) {
        arr[index[i]] = arr[index[i]] % z + arr[i] % z * z;
    }
    for (int i = 0; i < n; i++) {
        arr[i] = arr[i] / z;
    }
}
