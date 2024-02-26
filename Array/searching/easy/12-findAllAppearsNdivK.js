/*
Given Array of size n and a number k, find all elements that appear more than n/k times
Time Complexity: O(N)
Auxiliary Space: O(N)
*/
function morethanNdK(a, n, k) {
  let x = n / k;
  // Hash map initialization
  let y = new Map();
  // count the frequency of each element.
  for (let i = 0; i < n; i++) {
    // is element doesn't exist in hash table
    if (!y.has(a[i])) y.set(a[i], 1);
    // if element does exist in the hash table
    else {
      let count = y.get(a[i]);
      y.set(a[i], count + 1);
    }
  }

  // iterate over each element in the hash table
  // and check their frequency, if it is more than
  // n/k, print it.
  for (let [key, value] of y.entries()) {
    let temp = value;
    if (temp > x) document.write(key + "<br>");
  }
}
