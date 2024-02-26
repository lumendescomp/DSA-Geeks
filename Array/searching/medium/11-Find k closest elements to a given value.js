/*
Time complexity: O(Logn + k).
Auxiliary Space: O(1)
*/
function findCrossOver(arr, low, high, x) {
  // Base cases
  if (arr[high] <= x)
    // x is greater than all
    return high;

  if (arr[low] > x)
    // x is smaller than all
    return low;

  // Find the middle point
  var mid = low + high; // 2 // low + (high - low)// 2

  // If x is same as middle element,
  // then return mid
  if (arr[mid] <= x && arr[mid + 1] > x) return mid;

  // If x is greater than arr[mid], then
  // either arr[mid + 1] is ceiling of x
  // or ceiling lies in arr[mid+1...high]
  if (arr[mid] < x) return findCrossOver(arr, mid + 1, high, x);

  return findCrossOver(arr, low, mid - 1, x);
}
function printKclosest(arr, x, k, n) {
  // Find the crossover point
  var l = findCrossOver(arr, 0, n - 1, x);
  var r = l + 1; // Right index to search
  var count = 0; // To keep track of count of
  // elements already printed

  // If x is present in arr[], then reduce
  // left index. Assumption: all elements
  // in arr[] are distinct
  if (arr[l] == x) l -= 1;

  // Compare elements on left and right of crossover
  // point to find the k closest elements
  while (l >= 0 && r < n && count < k) {
    if (x - arr[l] < arr[r] - x) {
      document.write(arr[l] + " ");
      l -= 1;
    } else {
      document.write(arr[r] + " ");
      r += 1;
    }
    count += 1;
  }

  // If there are no more elements on right
  // side, then print left elements
  while (count < k && l >= 0) {
    print(arr[l]);
    l -= 1;
    count += 1;
  }

  // If there are no more elements on left
  // side, then print right elements
  while (count < k && r < n) {
    print(arr[r]);
    r += 1;
    count += 1;
  }
}

/*
Time Complexity: O(n log k), where n is the size of the array and k is the number of elements to be returned. The priority queue takes O(log k) time to insert an element and O(log k) time to remove the top element. Therefore, traversing through the array and inserting elements into the priority queue takes O(n log k) time. Popping elements from the priority queue and pushing them into the result vector takes O(k log k) time. Therefore, the total time complexity is O(n log k + k log k) which is equivalent to O(n log k).
Auxiliary Space: O(k), as we are using a priority queue of size k+1 and a vector of size k to store the result.
*/

function findClosestElements(arr, k, x) {
  // Create a max heap to store the pairs of absolute
  // differences and negative values
  const maxH = new MaxHeap();

  const n = arr.length;

  for (let i = 0; i < n; i++) {
    // Skip if the element is equal to x
    if (arr[i] === x) continue;

    // Calculate the absolute difference and add the
    // pair to the max heap
    const diff = Math.abs(arr[i] - x);
    maxH.insert({ diff: diff, value: -arr[i] });

    // If the size of the max heap exceeds k, remove the
    // element with the maximum absolute difference
    if (maxH.size() > k) maxH.extractMax();
  }

  // Store the result in an array
  const result = [];

  // Retrieve the top k elements from the max heap
  while (!maxH.isEmpty()) {
    // Get the top element from the max heap
    const p = maxH.extractMax();

    // Add the negative value to the result array
    result.push(-p.value);
  }

  // Reverse the result array to get the closest numbers
  // in ascending order
  result.reverse();

  return result;
}
// MaxHeap class implementation
class MaxHeap {
  constructor() {
    this.heap = [];
  }

  size() {
    return this.heap.length;
  }

  isEmpty() {
    return this.heap.length === 0;
  }

  insert(value) {
    this.heap.push(value);
    this.heapifyUp(this.heap.length - 1);
  }

  extractMax() {
    if (this.isEmpty()) return null;

    const max = this.heap[0];
    const lastElement = this.heap.pop();

    if (!this.isEmpty()) {
      this.heap[0] = lastElement;
      this.heapifyDown(0);
    }

    return max;
  }

  heapifyUp(index) {
    const parentIndex = Math.floor((index - 1) / 2);

    if (
      parentIndex >= 0 &&
      this.heap[parentIndex].diff < this.heap[index].diff
    ) {
      this.swap(parentIndex, index);
      this.heapifyUp(parentIndex);
    }
  }

  heapifyDown(index) {
    const leftChildIndex = 2 * index + 1;
    const rightChildIndex = 2 * index + 2;
    let largestIndex = index;

    if (
      leftChildIndex < this.heap.length &&
      this.heap[leftChildIndex].diff > this.heap[largestIndex].diff
    ) {
      largestIndex = leftChildIndex;
    }

    if (
      rightChildIndex < this.heap.length &&
      this.heap[rightChildIndex].diff > this.heap[largestIndex].diff
    ) {
      largestIndex = rightChildIndex;
    }

    if (largestIndex !== index) {
      this.swap(largestIndex, index);
      this.heapifyDown(largestIndex);
    }
  }

  swap(index1, index2) {
    [this.heap[index1], this.heap[index2]] = [
      this.heap[index2],
      this.heap[index1],
    ];
  }
}

//Exercise: Extend the optimized solution to work for duplicates also, i.e., to work for arrays where elements don’t have to be distinct.

/*
The time complexity of the above solution is O(n) and doesn’t require any extra space.
*/
function find_k_closest_elements(nums, target, k, n) {
  let left = 0;
  let right = n - 1;

  // Use binary search to find the closest elements
  while (right - left >= k) {
    // Compare the absolute differences between the target and elements at left and right pointers
    if (Math.abs(nums[left] - target) > Math.abs(nums[right] - target)) {
      left++;
    } else {
      right--;
    }
  }

  // Print the `k` closest elements
  while (left <= right) {
    console.log(nums[left], (end = " "));
    left++;
  }
}
