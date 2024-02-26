//Solution should be O(n) with O(1) auxiliary space
let arr = [1, 3, 7, 5, 6, 2];
let n = arr.length;

//O(n) solution with O(n) auxiliary space
function missingNumber(arr, N) {
  let i;
  let temp = [];
  for (i = 0; i <= N; i++) {
    temp[i] = 0;
  }

  for (i = 0; i < N; i++) {
    temp[arr[i] - 1] = 1;
  }

  let ans = 0;
  for (i = 0; i <= N; i++) {
    if (temp[i] == 0) ans = i + 1;
  }
  console.log(ans);
}

function optimizedMissingNumber(arr, N) {
  let total = Math.floor(((n + 1) * (n + 2)) / 2);
  for (let i = 0; i < n; i++) total -= a[i];
  return total;
}
