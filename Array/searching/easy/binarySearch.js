let array = [1, 2, 3, 4, 5, 6];

function binarySearch(arr, n, begin, end) {
  if (begin <= end) {
    let mid = Math.floor((begin + end) / 2);
    if (n == arr[mid]) {
      return mid;
    }
    if (n < arr[mid]) {
      return binarySearch(arr, n, begin, mid - 1);
    }
    return binarySearch(arr, n, mid + 1, end);
  }
  return -1;
}
