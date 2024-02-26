/*Time Complexity: O(n)
Auxiliary Space: O(1) */
function getMedian(ar1, ar2, n) {
  var i = 0; /* Current index of i/p array ar1[] */
  var j = 0; /* Current index of i/p array ar2[] */
  var count;
  var m1 = -1,
    m2 = -1;

  /* Since there are 2n elements, median will be average
    of elements at index n-1 and n in the array obtained after
    merging ar1 and ar2 */
  for (count = 0; count <= n; count++) {
    /*Below is to handle case where all elements of ar1[] are
        smaller than smallest(or first) element of ar2[]*/
    if (i == n) {
      m1 = m2;
      m2 = ar2[0];
      break;
    } else if (j == n) {
      /*Below is to handle case where all elements of ar2[] are
        smaller than smallest(or first) element of ar1[]*/
      m1 = m2;
      m2 = ar1[0];
      break;
    }
    /* equals sign because if two
            arrays have some common elements */
    if (ar1[i] <= ar2[j]) {
      m1 = m2; /* Store the prev median */
      m2 = ar1[i];
      i++;
    } else {
      m1 = m2; /* Store the prev median */
      m2 = ar2[j];
      j++;
    }
  }

  return (m1 + m2) / 2;
}
/* Time Complexity: O(log n)
Auxiliary Space: O(1)*/
function getMedian(arr1, arr2, n) {
  // Define the variables low, high, pos and ans
  // According to given constraints, all numbers are in this range
  let low = -1e9,
    high = 1e9,
    pos = n,
    ans = 0.0;

  // Binary search to find the element which will be
  // present at pos = totalLen/2 after merging two
  // arrays in sorted order
  while (low <= high) {
    let mid = low + ((high - low) >> 1);

    // Total number of elements in arrays which are
    // less than mid
    // Note: The function upper_bound is not available in JavaScript
    // You need to find an equivalent solution or implement it yourself
    let ub = 0;

    if (ub <= pos) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  ans = low;

  // As there are even number of elements, we will
  // also have to find element at pos = totalLen/2 - 1
  pos--;
  low = -1e9;
  high = 1e9;
  while (low <= high) {
    let mid = low + ((high - low) >> 1);
    let ub = 0;

    if (ub <= pos) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  // Average of two elements in case of even
  // number of elements
  ans = (ans + low) / 2;

  return ans;
}
/* C++
Time Complexity: O(log n)
Auxiliary Space: O(1)

#include <bits/stdc++.h>
using namespace std;
 
double getMedian(int arr1[], int arr2[], int n)
{
    // according to given constraints all numbers are in
    // this range
    int low = (int)-1e9, high = (int)1e9;
 
    int pos = n;
    double ans = 0.0;
    // binary search to find the element which will be
    // present at pos = totalLen/2 after merging two
    // arrays in sorted order
    while (low <= high) {
        int mid = low + ((high - low) >> 1);
 
        // total number of elements in arrays which are
        // less than mid
        int ub = upper_bound(arr1, arr1 + n, mid) - arr1
                 + upper_bound(arr2, arr2 + n, mid) - arr2;
 
        if (ub <= pos)
            low = mid + 1;
        else
            high = mid - 1;
    }
 
    ans = low;
 
    // As there are even number of elements, we will
    // also have to find element at pos = totalLen/2 - 1
    pos--;
    low = (int)-1e9;
    high = (int)1e9;
    while (low <= high) {
        int mid = low + ((high - low) >> 1);
        int ub = upper_bound(arr1, arr1 + n, mid) - arr1
                 + upper_bound(arr2, arr2 + n, mid) - arr2;
 
        if (ub <= pos)
            low = mid + 1;
        else
            high = mid - 1;
    }
 
    // average of two elements in case of even
    // number of elements
    ans = (ans + low) / 2;
 
    return ans;
}
*/
