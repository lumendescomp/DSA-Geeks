/*Time Complexity: O(logN) 
Auxiliary Space: O(1) */

function binarySearch(arr, l, r, x) {
  if (r >= l) {
    let mid = l + Math.floor((r - l) / 2);
    if (arr[mid] == x) return mid;
    if (arr[mid] > x) return binarySearch(arr, l, mid - 1, x);
    return binarySearch(arr, mid + 1, r, x);
  }
  return -1;
}

// function takes an infinite size array and a key to be
// searched and returns its position if found else -1.
// We don't know size of arr[] and we can assume size to be
// infinite in this function.
// NOTE THAT THIS FUNCTION ASSUMES arr[] TO BE OF INFINITE SIZE
// THEREFORE, THERE IS NO INDEX OUT OF BOUND CHECKING
function findPos(arr, key) {
  let l = 0,
    h = 1;
  let val = arr[0];

  // Find h to do binary search
  while (val < key) {
    l = h; // store previous high
    h = 2 * h; // double high index
    val = arr[h]; // update new val
  }

  // at this point we have updated low and
  // high indices, Thus use binary search
  // between them
  return binarySearch(arr, l, h, key);
}
