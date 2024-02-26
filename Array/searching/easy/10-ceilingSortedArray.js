/*
Given a sorted array and a value x, the ceiling of x is the smallest element in an array greater than or equal to x, and the floor is the greatest element smaller than or equal to x. Assume that the array is sorted in non-decreasing order. Write efficient functions to find the floor and ceiling of x.
For example, let the input array be {1, 2, 8, 10, 10, 12, 19}
For x = 0:    floor doesn't exist in array,  ceil  = 1
For x = 1:    floor  = 1,  ceil  = 1
For x = 5:    floor  = 2,  ceil  = 8
For x = 20:   floor  = 19,  ceil doesn't exist in array
*/
//Time Complexity: O(n),
//Auxiliary Space: O(1)
function ceilSearch(arr, low, high, x) {
  let i;

  /* If x is smaller than or equal to first element, 
        then return the first element */
  if (x <= arr[low]) return low;

  /* Otherwise, linearly search for ceil value */
  for (i = low; i < high; i++) {
    if (arr[i] == x) return i;

    /* if x lies between arr[i] and arr[i+1] including 
        arr[i+1], then return arr[i+1] */
    if (arr[i] < x && arr[i + 1] >= x) return i + 1;
  }

  /* If we reach here then 
    x is greater than the last element 
        of the array, return -1 in this case */
  return -1;
}

//Time Complexity: O(log(n)),
//Auxiliary Space: O(1)
function ceilSearch(arr, low, high, x) {
  let mid;
  if (x <= arr[low]) return low;
  if (x > arr[high]) return -1;
  mid = (low + high) / 2;
  if (arr[mid] == x) return mid;
  else if (arr[mid] < x) {
    if (mid + 1 <= high && x <= arr[mid + 1]) return mid + 1;
    else return ceilSearch(arr, mid + 1, high, x);
  } else {
    if (mid - 1 >= low && x > arr[mid - 1]) return mid;
    else return ceilSearch(arr, low, mid - 1, x);
  }
}
