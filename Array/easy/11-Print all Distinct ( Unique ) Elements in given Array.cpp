/*
Time Complexity: O(n).
Auxiliary Space: O(n)
*/
// ---------------------CODE-----------------------
void printDistinct(int arr[],int n)
{
    // Creates an empty hashset
    unordered_set<int> s;
 
    // Traverse the input array
    for (int i=0; i<n; i++)
    {
        // if element is not present then s.count(element) return 0 else return 1
        // hashtable and print it
        if (!s.count(arr[i]))  // <--- avg O(1) time
        {
            s.insert(arr[i]);
            cout << arr[i] << " ";
        }
    }
}

/*

*/
// ---------------------CODE-----------------------

