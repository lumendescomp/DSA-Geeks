/*
Note: This method doesn’t work if there are duplicate elements in the array.
Time Complexity: O(Log n)
Auxiliary Space : O(Log n)
*/
// ---------------------CODE-----------------------
int findFirstMissing(int array[],  
                    int start, int end) 
{ 
    if (start > end) 
        return end + 1; 
  
    if (start != array[start]) 
        return start; 
  
    int mid = (start + end) / 2; 
  
    // Left half has all elements  
    // from 0 to mid 
    if (array[mid] == mid) 
        return findFirstMissing(array,  
                            mid+1, end); 
  
    return findFirstMissing(array, start, mid); 
} 

/*

*/
// ---------------------CODE-----------------------

