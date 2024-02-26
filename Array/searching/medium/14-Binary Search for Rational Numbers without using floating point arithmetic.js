/* Time Complexity: O(log n)
Auxiliary Space: O(1),  since no extra space has been taken.*/

// Javascript program for Binary Search for Rational Numbers
// without using floating point arithmetic
class Rational {
  constructor(p, q) {
    this.p = p;
    this.q = q;
  }
}

// Utility function to compare two Rational numbers
// 'a' and 'b'. It returns
// 0 -. When 'a' and 'b' are same
// 1 -. When 'a' is greater
//-1 -. When 'b' is greater
function compare(a, b) {
  // If a/b == c/d then a*d = b*c:
  // method to ignore division
  if (a.p * b.q == a.q * b.p) return 0;
  if (a.p * b.q > a.q * b.p) return 1;
  return -1;
}

// Returns index of x in arr[l..r] if it is present, else
// returns -1. It mainly uses Binary Search.
function binarySearch(arr, l, r, x) {
  if (r >= l) {
    let mid = l + Math.floor((r - l) / 2);

    // If the element is present at the middle itself
    if (compare(arr[mid], x) == 0) return mid;

    // If element is smaller than mid, then it can
    // only be present in left subarray
    if (compare(arr[mid], x) > 0) return binarySearch(arr, l, mid - 1, x);

    // Else the element can only be present in right
    // subarray
    return binarySearch(arr, mid + 1, r, x);
  }

  return -1;
}

// Driver method
let arr = [
  new Rational(1, 5),
  new Rational(2, 3),
  new Rational(3, 2),
  new Rational(13, 2),
];
let x = new Rational(3, 2);
let n = arr.length;
document.write("Element found at index ", binarySearch(arr, 0, n - 1, x));
