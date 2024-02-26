/*
Find the element before which all the elements are smaller than it, and after which all are greater
Input: arr[] = {5, 1, 4, 3, 6, 8, 10, 7, 9}; 
Output: 4 
Explanation: All elements on left of arr[4] are smaller than it 
and all elements on right are greater.
*/
/*
Time Complexity: O(n²)
Auxiliary Space: O(1)
*/
function findElement(arr, n) {
  // Traverse array from 1st to n-1 th index because
  // Extrem elements can't be our answer
  for (let i = 1; i < n - 1; i++) {
    if (check(arr, n, i)) {
      return i;
    }
  }

  // If there was no element matching criteria
  return -1;
}
function check(arr, n, ind) {
  let i = ind - 1;
  let j = ind + 1;

  while (i >= 0) {
    if (arr[i] > arr[ind]) {
      return false;
    }
    i--;
  }

  while (j < n) {
    if (arr[j] < arr[ind]) {
      return false;
    }
    j++;
  }

  return true;
}

/*
Time Complexity: O(n)
Auxiliary Space: O(n)
*/
function findElement(arr, n) {
  // leftMax[i] stores maximum of arr[0..i-1]
  var leftMax = Array(n).fill(0);
  leftMax[0] = Number.MIN_VALUE;

  // Fill leftMax[1..n-1]
  for (i = 1; i < n; i++) leftMax[i] = Math.max(leftMax[i - 1], arr[i - 1]);

  // Initialize minimum from right
  var rightMin = Number.MAX_VALUE;

  // Traverse array from right
  for (i = n - 1; i >= 0; i--) {
    // Check if we found a required element
    if (leftMax[i] < arr[i] && rightMin > arr[i]) return i;

    // Update right minimum
    rightMin = Math.min(rightMin, arr[i]);
  }

  // If there was no element
  // matching criteria
  return -1;
}
