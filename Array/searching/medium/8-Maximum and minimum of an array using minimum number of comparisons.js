/*
The idea is to divide the array into two parts and compare the maximums and minimums of the two parts to get the maximum and the minimum of the whole array.
Time Complexity: O(n)
Auxiliary Space: O(log n)
*/

class Pair {
  constructor() {
    this.min = -1;
    this.max = 10000000;
  }
}

function getMinMax(arr, low, high) {
  var minmax = new Pair();
  var mml = new Pair();
  var mmr = new Pair();
  var mid;

  // If there is only one element
  if (low == high) {
    minmax.max = arr[low];
    minmax.min = arr[low];
    return minmax;
  }

  /* If there are two elements */
  if (high == low + 1) {
    if (arr[low] > arr[high]) {
      minmax.max = arr[low];
      minmax.min = arr[high];
    } else {
      minmax.max = arr[high];
      minmax.min = arr[low];
    }
    return minmax;
  }

  /* If there are more than 2 elements */
  mid = parseInt((low + high) / 2);
  mml = getMinMax(arr, low, mid);
  mmr = getMinMax(arr, mid + 1, high);

  /* compare minimums of two parts */
  if (mml.min < mmr.min) {
    minmax.min = mml.min;
  } else {
    minmax.min = mmr.min;
  }

  /* compare maximums of two parts */
  if (mml.max > mmr.max) {
    minmax.max = mml.max;
  } else {
    minmax.max = mmr.max;
  }

  return minmax;
}

/* Driver program to test above function */
var arr = [1000, 11, 445, 1, 330, 3000];
var arr_size = 6;
var minmax = getMinMax(arr, 0, arr_size - 1);

/*
Number of Comparisons:
Let the number of comparisons be T(n). T(n) can be written as follows: 

T(n) = T(floor(n/2)) + T(ceil(n/2)) + 2
T(2) = 1
T(1) = 0

If n is a power of 2, then we can write T(n) as: 

T(n) = 2T(n/2) + 2

After solving the above recursion, we get 

T(n) = 3n/2 -2

Thus, the approach does 3n/2 -2 comparisons if n is a power of 2. And it does more than 3n/2 -2 comparisons if n is not a power of 2.
*/

/*
The idea is that when n is odd then initialize min and max as the first element. If n is even then initialize min and max as minimum and maximum of the first two elements respectively. For the rest of the elements, pick them in pairs and compare their maximum and minimum with max and min respectively. 
Time Complexity: O(n)
Auxiliary Space: O(1) as no extra space was needed.
*/
function getMinMax(arr) {
  let n = arr.length;
  let mx, mn, i;

  // If array has even number of elements then
  // initialize the first two elements as minimum
  // and maximum
  if (n % 2 == 0) {
    mx = Math.max(arr[0], arr[1]);
    mn = Math.min(arr[0], arr[1]);

    // set the starting index for loop
    i = 2;
  }

  // If array has odd number of elements then
  // initialize the first element as minimum
  // and maximum
  else {
    mx = mn = arr[0];

    // set the starting index for loop
    i = 1;
  }

  // In the while loop, pick elements in pair and
  // compare the pair with max and min so far
  while (i < n - 1) {
    if (arr[i] < arr[i + 1]) {
      mx = Math.max(mx, arr[i + 1]);
      mn = Math.min(mn, arr[i]);
    } else {
      mx = Math.max(mx, arr[i]);
      mn = Math.min(mn, arr[i + 1]);
    }

    // Increment the index by 2 as two
    // elements are processed in loop
    i += 2;
  }

  return [mx, mn];
}

// Driver Code

let arr = [1000, 11, 445, 1, 330, 3000];
let mx = getMinMax(arr)[0];
let mn = getMinMax(arr)[1];

/*
Number of Comparisons:
The total number of comparisons: Different for even and odd n, see below: 

If n is odd: 3*(n-1)/2

If n is even: 1 + 3*(n-2)/2 = 3n/2-2, 1 comparison for initializing min and max,
and 3(n-2)/2 comparisons for rest of the elements

The third and fourth approaches make an equal number of comparisons when n is a power of 2. 
In general, method 4 seems to be the best.
*/
