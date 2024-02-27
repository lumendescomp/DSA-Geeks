/* Method 3 (O(n1 + n2) Time and O(n1 + n2) Extra Space) */
function mergeArrays(arr1, arr2, n1, n2, arr3) {
  var i = 0,
    j = 0,
    k = 0;

  // Traverse both array
  while (i < n1 && j < n2) {
    // Check if current element of first
    // array is smaller than current element
    // of second array. If yes, store first
    // array element and increment first array
    // index. Otherwise do same with second array
    if (arr1[i] < arr2[j]) arr3[k++] = arr1[i++];
    else arr3[k++] = arr2[j++];
  }

  // Store remaining elements of first array
  while (i < n1) arr3[k++] = arr1[i++];

  // Store remaining elements of second array
  while (j < n2) arr3[k++] = arr2[j++];
}
/* Time Complexity: O(M * N)
Auxiliary Space: O(1)*/
function merge(m, n) {
  // Iterate through all elements of ar2[] starting from
  // the last element
  for (let i = n - 1; i >= 0; i--) {
    /* Find the smallest element greater than ar2[i]. Move all
               elements one position ahead till the smallest greater
               element is not found */
    let j,
      last = arr1[m - 1];
    for (j = m - 2; j >= 0 && arr1[j] > arr2[i]; j--) arr1[j + 1] = arr1[j];

    // If there was a greater element
    if (last > arr2[i]) {
      arr1[j + 1] = arr2[i];
      arr2[i] = last;
    }
  }
}

/* Time Complexity: O((N+M) * log(N+M))
Auxiliary Space: O(1)*/
function merge(m, n) {
  var i = 0,
    j = 0,
    k = n - 1;
  while (i <= k && j < m) {
    if (arr1[i] < arr2[j]) i++;
    else {
      var temp = arr2[j];
      arr2[j] = arr1[k];
      arr1[k] = temp;
      j++;
      k--;
    }
  }
  arr1.sort((a, b) => a - b);
  arr2.sort((a, b) => a - b);
}

/* Merge two sorted arrays with O(1) extra space using Euclidean Division Lemma:
Time Complexity: O(M + N)
Auxiliary Space: O(1), since no extra space has been taken*/

/* */
