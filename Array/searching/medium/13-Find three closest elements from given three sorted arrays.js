/* Time complexity of this solution is O(p + q + r) where p, q and r are sizes of A[], B[] and C[] respectively.
Auxiliary space: O(1) as constant space is required.*/
function findClosest(A, B, C, p, q, r) {
  var diff = Math.pow(10, 9); // Initialize min diff

  // Initialize result
  var res_i = 0,
    res_j = 0,
    res_k = 0;

  // Traverse arrays
  var i = 0,
    j = 0,
    k = 0;
  while (i < p && j < q && k < r) {
    // Find minimum and maximum of current three elements
    var minimum = Math.min(A[i], Math.min(B[j], C[k]));
    var maximum = Math.max(A[i], Math.max(B[j], C[k]));

    // Update result if current diff is less than the min
    // diff so far
    if (maximum - minimum < diff) {
      (res_i = i), (res_j = j), (res_k = k);
      diff = maximum - minimum;
    }

    // We can't get less than 0 as values are absolute
    if (diff == 0) break;

    // Increment index of array with smallest value
    if (A[i] == minimum) i++;
    else if (B[j] == minimum) j++;
    else k++;
  }

  // Print result
  document.write(A[res_i] + " " + B[res_j] + " " + C[res_k]);
}
