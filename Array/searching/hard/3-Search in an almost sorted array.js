/* Given a sorted array arr[] of size N, some elements of array are moved to either of the adjacent positions, i.e., arr[i] may be present at arr[i+1] or arr[i-1] i.e. arr[i] can only be swapped with either arr[i+1] or arr[i-1]. The task is to search for an element in this array.*/

/* Time complexity: O(Logn).
Auxiliary Space: O(1)*/
function binarySearch(arr, l, r, x) {
  if (r >= l) {
    let mid = l + Math.floor((r - l) / 2);

    // If the element is present at
    // one of the middle 3 positions
    if (arr[mid] == x) return mid;
    if (mid > l && arr[mid - 1] == x) return mid - 1;
    if (mid < r && arr[mid + 1] == x) return mid + 1;

    // If element is smaller than mid, then
    // it can only be present in left subarray
    if (arr[mid] > x) return binarySearch(arr, l, mid - 2, x);

    // Else the element can only be present
    // in right subarray
    return binarySearch(arr, mid + 2, r, x);
  }

  // We reach here when element is
  // not present in array
  return -1;
}
/* */
