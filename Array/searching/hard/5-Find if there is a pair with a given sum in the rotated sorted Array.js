/*Time Complexity: O(n), where n is the length of the input array.
Space Complexity: O(1). */
function findPair(arr, x) {
  const n = arr.length;
  // find pivot element
  let pivot = 0;
  for (let i = 0; i < n - 1; i++) {
    if (arr[i] > arr[i + 1]) {
      pivot = i + 1;
      break;
    }
  }
  let left = pivot;
  let right = pivot - 1;
  while (left !== right) {
    if (arr[left] + arr[right] === x) {
      return true;
    } else if (arr[left] + arr[right] < x) {
      left = (left + 1) % n;
    } else {
      right = (right - 1 + n) % n;
    }
  }
  return false;
}
/* */

/* */
