/*
Time Complexity: O(log n)
Auxiliary Space: O(log n) 
*/
function binarySearch(arr, low, high) {
  if (high >= low) {
    let mid = math.floor(low + (high - low) / 2);
    if (mid == arr[mid]) return mid;
    let res = -1;
    if (mid + 1 <= arr[high]) res = binarySearch(arr, mid + 1, high);
    if (res != -1) return res;
    if (mid - 1 >= arr[low]) return binarySearch(arr, low, mid - 1);
  }

  /* Return -1 if there is no Fixed Point */
  return -1;
}
