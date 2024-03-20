/*
Time Complexity: O(n)
Auxiliary Space: O(1)
*/
// ---------------------CODE-----------------------
// Function to rearrange an array
// such that arr[i] = i.
void fixArray(int A[], int len)
{
    for (int i = 0; i < len; i++)
    {
        if (A[i] != -1 && A[i] != i)
        {
            int x = A[i];
 
            // check if desired place
            // is not vacate
            while (A[x] != -1 && A[x] != x) 
            {
                // store the value from
                // desired place
                int y = A[x];
 
                // place the x to its correct
                // position
                A[x] = x;
 
                // now y will become x, now
                // search the place for x
                x = y;
            }
 
            // place the x to its correct
            // position
            A[x] = x;
 
            // check if while loop hasn't
            // set the correct value at A[i]
            //Handling Duplicates or Invalid Values: If there are duplicate values or values that do not have a corresponding index (e.g., larger than the array length or negative values other than -1), there will be elements that cannot be placed in their "correct" position.
            if (A[i] != i)
            {
                // if not then put -1 at
                // the vacated place
                A[i] = -1;
            }
        }
    }
}
 
