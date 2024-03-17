/*
Time Complexity: O(N), as we are using a loop to traverse N times.
Auxiliary Space: O(1), as we are not using any extra space.
*/
// ---------------------CODE-----------------------
void leftRotate(int arr[], int n, int k)
{
    /* To get the starting point of rotated array */
    int mod = k % n;
 
    // Prints the rotated array from start position
    for (int i = 0; i < n; i++)
        cout << (arr[(mod + i) % n]) << " ";
 
    cout << "\n";
}

/*

*/
// ---------------------CODE-----------------------

