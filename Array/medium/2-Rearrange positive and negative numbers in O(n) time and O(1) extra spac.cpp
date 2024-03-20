/*
Time Complexity: O(n) where n is number of elements in given array. As, we are using a loop to traverse N times so it will cost us O(N) time 
Auxiliary Space: O(1), as we are not using any extra space.
*/
// ---------------------CODE-----------------------
void GFG :: rearrange(int arr[], int n)
{
    // The following few lines are 
    // similar to partition process
    // of QuickSort. The idea is to 
    // consider 0 as pivot and
    // divide the array around it.
    int i = -1;
    for (int j = 0; j < n; j++)
    {
        if (arr[j] < 0)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
 
    // Now all positive numbers are at 
    // end and negative numbers at the
    // beginning of array. Initialize 
    // indexes for starting point of
    // positive and negative numbers 
    // to be swapped
    int pos = i + 1, neg = 0;
 
    // Increment the negative index by 
    // 2 and positive index by 1,
    // i.e., swap every alternate negative 
    // number with next positive number
    while (pos < n && neg < pos && 
                     arr[neg] < 0)
    {
        swap(&arr[neg], &arr[pos]);
        pos++;
        neg += 2;
    }
}

/*

*/
// ---------------------CODE-----------------------

