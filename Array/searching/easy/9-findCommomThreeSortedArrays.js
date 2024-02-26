//Given three Sorted arrays in non-decreasing order, print all common elements in these arrays.
//Time complexity: O(n1 + n2 + n3), where n1, n2 and n3 are sizes of ar1[], ar2[] and ar3[] respectively.
//Auxiliary Space: O(max(n1,n2,n3))
function findIntersection(arr1, arr2) {
  let i = 0;
  let j = 0;
  const temp = [];

  while (i < arr1.length && j < arr2.length) {
    if (arr1[i] < arr2[j]) {
      i++;
    } else if (arr2[j] < arr1[i]) {
      j++;
    } else {
      temp.push(arr1[i]);
      i++;
      j++;
    }
  }

  return temp;
}

//Time complexity: O(n1 + n2 + n3), In the worst case, the largest-sized array may have all small elements and the middle-sized array has all middle elements.
//Auxiliary Space:  O(1)
function findCommon(ar1, ar2, ar3, n1, n2, n3) {
  // Initialize starting indexes
  // for ar1[], ar2[] and ar3[]
  var i = 0,
    j = 0,
    k = 0;

  // Iterate through three arrays
  // while all arrays have elements
  while (i < n1 && j < n2 && k < n3) {
    // If x = y and y = z, print any of them and move ahead
    // in all arrays
    if (ar1[i] == ar2[j] && ar2[j] == ar3[k]) {
      document.write(ar1[i] + " ");
      i++;
      j++;
      k++;
    }

    // x < y
    else if (ar1[i] < ar2[j]) i++;
    // y < z
    else if (ar2[j] < ar3[k]) j++;
    // We reach here when x > y and z < y, i.e., z is smallest
    else k++;
  }
}
