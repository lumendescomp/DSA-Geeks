// An Array of integers is given, both +ve and -ve. You need to find the two elements such that their sum is closest to zero.
//Time Complexity: complexity to sort + complexity of finding the optimum pair = O(nlogn) + O(n) = O(nlogn)
//Auxiliary Space: O(1)

function minAbsSumPair(arr, n) {
  // Variables to keep track of current sum and minimum sum
  let sum,
    min_sum = 999999;

  // left and right index variables
  let l = 0,
    r = n - 1;

  // variable to keep track of the left and right pair for min_sum
  let min_l = l,
    min_r = n - 1;

  /* Array should have at least two elements*/
  if (n < 2) {
    document.write("Invalid Input");
    return;
  }

  /* Sort the elements */
  sort(arr, l, r);

  while (l < r) {
    sum = arr[l] + arr[r];

    /*If abs(sum) is less then update the result items*/
    if (Math.abs(sum) < Math.abs(min_sum)) {
      min_sum = sum;
      min_l = l;
      min_r = r;
    }
    if (sum < 0) l++;
    else r--;
  }

  document.write(
    " The two elements whose " +
      "sum is minimum are " +
      arr[min_l] +
      " and " +
      arr[min_r]
  );
}
