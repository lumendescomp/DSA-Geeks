//Given an unsorted array and a number n, find if there exists a pair of elements in the array whose difference is n.

//Best solution is O(n) | Auxiliary Space: O(n)
function findPairOptimized(arr, size, n) {
  let mpp = new Map();

  // Traverse the array
  for (let i = 0; i < size; i++) {
    // Update frequency
    // of arr[i]
    if (mpp.has(arr[i])) mpp.set(arr[i], mpp.get(arr[i]) + 1);
    else mpp.set(arr[i], 1);

    // Check if any element whose frequency
    // is greater than 1 exist or not for n == 0
    if (n == 0 && mpp.get(arr[i]) > 1) return true;
  }

  // Check if difference is zero and
  // we are unable to find any duplicate or
  // element whose frequency is greater than 1
  // then no such pair found.
  if (n == 0) return false;

  for (let i = 0; i < size; i++) {
    if (mpp.has(n + arr[i])) {
      document.write("Pair Found: (" + arr[i] + ", " + +(n + arr[i]) + ")");
      return true;
    }
  }
  document.write("No Pair found");
  return false;
}

//Time Complexity: O(n*log(n)) [Sorting is still required as first step], Where n is number of element in given array
//Auxiliary Space: O(1)
const findPair = (arr, size, n) => {
  // Step-1 Sort the array
  arr.sort((a, b) => a - b);

  // Initialize positions of two elements
  let l = 0;
  let r = 1;

  // take absolute value of difference
  // this does not affect the pair as A-B=diff is same as B-A= -diff
  n = Math.abs(n);

  // Search for a pair

  // These loop running conditions are sufficient
  while (l <= r && r < size) {
    let diff = arr[r] - arr[l];
    if (diff === n && l !== r) {
      // we need distinct elements in pair
      // so l!==r
      console.log("Pair Found: (" + arr[l] + ", " + arr[r] + ")");
      return true;
    } else if (diff > n)
      // try to reduce the diff
      l++;
    // Note if l==r then r will be advanced thus no
    // pair will be missed
    else r++;
  }
  console.log("No such pair");
  return false;
};
