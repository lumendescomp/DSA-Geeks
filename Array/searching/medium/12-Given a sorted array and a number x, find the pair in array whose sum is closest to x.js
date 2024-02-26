/*
Time Complexity: O(n), where n is the length of an Array.
Auxiliary Space: O(1)
*/
function printClosest(arr, n, x) {
  // To store indexes of result pair
  let res_l = 0,
    res_r = 0;

  // Initialize left and right indexes
  // and difference between
  // pair sum and x
  let l = 0,
    r = n - 1,
    diff = Number.MAX_VALUE;

  // While there are elements
  // between l and r
  while (r > l) {
    // Check if this pair is closer
    // than the closest pair so far
    if (Math.abs(arr[l] + arr[r] - x) < diff) {
      res_l = l;
      res_r = r;
      diff = Math.abs(arr[l] + arr[r] - x);
    }

    // If this pair has more sum,
    // move to smaller values.
    if (arr[l] + arr[r] > x) r--;
    // Move to larger values
    else l++;
  }

  document.write(" The closest pair is " + arr[res_l] + " and " + arr[res_r]);
}

/*
Time Complexity: O(n log n), because we are using a binary search algorithm to search for the pair, and for each element, we are performing a binary search, which has a time complexity of O(logn). Hence, the total time complexity of the approach becomes O(n log n).
Auxiliary Space: O(1), because we are not using any extra space to store the elements of the array or the result. The only extra space used is for storing some variables, which is constant and does not depend on the size of the input.
*/
function closestPair(arr, n, x) {
  // Initialize variables pointing to the
  // first and last elements of the array
  let l = 0,
    r = n - 1;

  // To store indexes of result pair
  let res_l, res_r;

  // variable to store current minimum difference
  let minDiff = Number.MAX_SAFE_INTEGER;

  // Iterate over the array using
  for (let i = 0; i < n; i++) {
    let e = arr[i];

    // Use binary search to find the element
    // 'elem' in the array such that 'e+elem'
    // is closest to 'x'.
    let left = i + 1,
      right = n - 1;
    while (left <= right) {
      let mid = Math.floor((left + right) / 2);

      if (arr[mid] + e == x) {
        res_l = i;
        res_r = mid;
        minDiff = 0;
        break;
      }

      // Check if this pair is closer than the
      // closest pair so far
      if (Math.abs(arr[mid] + e - x) < minDiff) {
        minDiff = Math.abs(arr[mid] + e - x);
        res_l = i;
        res_r = mid;
      }

      if (arr[mid] + e < x) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
  }
  // Print the pair
  console.log(`The closest pair is ${arr[res_l]} and ${arr[res_r]}`);
}
