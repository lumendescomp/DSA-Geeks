/*
Time Complexity: O(n)
Auxiliary Space: O(1)
*/
// ---------------------CODE-----------------------
void sort(int arr[], int n) 
{ 
  int i = 0; 
  while (i < n) { 
 
    // Finding the correct index 
    int correct = arr[i] - 1; 
 
    // Element index and value not match 
    // then swapping 
    if (arr[correct] != arr[i]) { 
 
      // Calling swap function 
      swap(arr[i], arr[correct]); 
    } 
    else { 
      i++; 
    } 
  } 
}

/*

*/
// ---------------------CODE-----------------------

