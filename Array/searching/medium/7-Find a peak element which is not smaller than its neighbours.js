/* RECURSIVE BS
Time Complexity: O(log N)
Auxiliary Space: O(log N)
*/
function findPeakUtil(arr, low, high, n) {
  // Find index of middle element
  // low + (high - low) / 2
  var mid = low + parseInt((high - low) / 2);

  // Compare middle element with its
  // neighbours (if neighbours exist)
  if (
    (mid == 0 || arr[mid - 1] <= arr[mid]) &&
    (mid == n - 1 || arr[mid + 1] <= arr[mid])
  )
    return mid;
  // If middle element is not peak and its
  // left neighbour is greater than it,
  // then left half must have a peak element
  else if (mid > 0 && arr[mid - 1] > arr[mid])
    return findPeakUtil(arr, low, mid - 1, n);
  // If middle element is not peak and its
  // right neighbour is greater than it,
  // then right half must have a peak element
  else return findPeakUtil(arr, mid + 1, high, n);
}

/* ITERATIVE BS
Time Complexity: O(log N)
Auxiliary Space: O(1)
*/
function findPeakUtil(arr, low, high, n) {
  let l = low;
  let r = high - 1;
  let mid;

  while (l <= r) {
    // finding the mid index by right shifting
    mid = (l + r) >> 1;

    // first case if mid is the answer
    if (
      (mid == 0 || arr[mid - 1] <= arr[mid]) &&
      (mid == n - 1 || arr[mid + 1] <= arr[mid])
    )
      break;

    // change the right pointer to mid-1
    if (mid > 0 && arr[mid - 1] > arr[mid]) r = mid - 1;
    // change the left pointer to mid+1
    else l = mid + 1;
  }

  return mid;
}
