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
/* Method 4: Using Maps (O(nlog(n) + mlog(m)) Time and O(N) Extra Space)*/
