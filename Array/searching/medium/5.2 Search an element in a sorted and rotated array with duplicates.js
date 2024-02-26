/* 
Time Complexity: O(log N), where n represents the size of the given array. If all the elements are same, we may end up doing a linear search.
Auxiliary Space: O(logN) due to recursive stack space.
*/
function search(arr, l, h, key) {
  if (l > h) return -1;

  let mid = parseInt((l + h) / 2, 10);
  if (arr[mid] == key) return mid;

  // The tricky case, just update left and right
  if (arr[l] == arr[mid] && arr[h] == arr[mid]) {
    ++l;
    --h;
    return search(arr, l, h, key);
  }

  // If arr[l...mid] is sorted
  if (arr[l] <= arr[mid]) {
    // As this subarray is sorted, we can quickly
    // check if key lies in any of the halves
    if (key >= arr[l] && key <= arr[mid]) return search(arr, l, mid - 1, key);

    // If key does not lie in the first half
    // subarray then divide the other half
    // into two subarrays such that we can
    // quickly check if key lies in the other half
    return search(arr, mid + 1, h, key);
  }

  // If arr[l..mid] first subarray is not sorted
  // then arr[mid... h] must be sorted subarray
  if (key >= arr[mid] && key <= arr[h]) return search(arr, mid + 1, h, key);

  return search(arr, l, mid - 1, key);
}

/*
Time Complexity: O(N), where n represents the size of the given array. If all the elements are same, we may end up doing a linear search.
Auxiliary Space: O(1) 
*/
function search(arr, low, high, key) {
  while (low <= high) {
    let mid = Math.floor(low + (high - low) / 2);

    if (arr[mid] === key) {
      // if we have found our target element
      // return the index of target element
      return mid;
    }

    if (arr[mid] === arr[low] && arr[mid] === arr[high]) {
      // It may happen in case of duplicates
      low++;
      high--;
      continue;
    }

    if (arr[low] <= arr[mid]) {
      // This means array is sorted from index low to
      // mid We will check that if target element lies
      // in left half or not

      if (key >= arr[low] && key < arr[mid]) {
        high = mid - 1;
      } else {
        // This means that our target lies in other
        // half of array So we shift low to mid+1 to
        // search in right half
        low = mid + 1;
      }
    } else {
      // This means array is sorted between mid and
      // high index

      // This will check our target element is
      // in right half or not
      if (key <= arr[high] && key > arr[mid]) {
        low = mid + 1;
      } else {
        // Means our target is in left half
        high = mid - 1;
      }
    }
  }

  // If target element is not present

  return -1;
}
