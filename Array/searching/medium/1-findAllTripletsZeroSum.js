/* 
Time Complexity: O(n2)
Auxiliary Space: O(1)
*/
function findTriplets(arr, n) {
  let found = false;

  // sort array elements
  arr.sort((a, b) => a - b);

  for (let i = 0; i < n - 1; i++) {
    // initialize left and right
    let l = i + 1;
    let r = n - 1;
    let x = arr[i];
    while (l < r) {
      if (x + arr[l] + arr[r] == 0) {
        // print elements if it's sum is zero
        document.write(x + " ");
        document.write(arr[l] + " ");
        document.write(arr[r] + " " + "<br>");
        l++;
        r--;
        found = true;
      }

      // If sum of three elements is less
      // than zero then increment in left
      else if (x + arr[l] + arr[r] < 0) l++;
      // if sum is greater than zero then
      // decrement in right side
      else r--;
    }
  }

  if (found == false) document.write(" No Triplet Found" + "<br>");
}

/*
Time Complexity: O(n2)
Auxiliary Space: O(n)
*/
function findTriplets(arr, n) {
  var found = false;

  for (var i = 0; i < n - 1; i++) {
    // Find all pairs with sum equals to
    // "-arr[i]"
    var s = new Set();
    for (var j = i + 1; j < n; j++) {
      var x = -(arr[i] + arr[j]);
      if (s.has(x)) {
        document.write(x + " " + arr[i] + " " + arr[j] + "<br>");
        found = true;
      } else s.add(arr[j]);
    }
  }

  if (found == false) document.write(" No Triplet Found");
}
