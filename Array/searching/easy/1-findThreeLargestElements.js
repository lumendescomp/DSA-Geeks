let array = [1, 9, 3, 7, 5, 4];

//Solution should be O(n)
function findThreeLargestElements(array) {
  if (array.length() < 3) return "Invalid Input";
  let first, second, third;
  third = first = second = Number.MIN_VALUE;
  array.forEach((elem) => {
    if (elem > first) {
      third = second;
      second = first;
      first = elem;
    } else if (elem > second) {
      third = second;
      second = elem;
    } else if (elem > third) third = elem;
  });
}
