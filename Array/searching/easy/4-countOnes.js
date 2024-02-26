//Input: arr[] = {1, 1, 0, 0, 0, 0, 0}
//Time complexity: O(Log(N))

function countOnes(arr, n) {
  let low = 0,
    high = n - 1;
  while (low <= high) {
    // get the middle index
    let mid = Math.floor((low + high) / 2);

    // else recur for left side
    if (arr[mid] < 1) high = mid - 1;
    // check if the element at middle index is last 1
    else {
      if (mid == n - 1 || arr[mid + 1] != 1) return mid + 1;
      else low = mid + 1;
    }
  }
}
