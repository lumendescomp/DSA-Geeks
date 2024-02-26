/*
Time complexity: O(n * log (mx-mn)), where mn be minimum and mx be maximum element of array.
Auxiliary Space: O(1)
*/
function count(nums, mid) {
  // function to calculate number of elements less than equal to mid
  var cnt = 0;

  for (var i = 0; i < nums.length; i++) if (nums[i] <= mid) cnt++;

  return cnt;
}

function kthSmallest(nums, k) {
  var low = Number.MAX_VALUE;
  var high = Number.MIN_VALUE;
  // calculate minimum and maximum the array.
  for (var i = 0; i < nums.length; i++) {
    low = Math.min(low, nums[i]);
    high = Math.max(high, nums[i]);
  }
  // Our answer range lies between minimum and
  // maximum element of the array on which Binary Search is Applied
  while (low < high) {
    var mid = Math.floor(low + (high - low) / 2);
    /*if the count of number of elements in the array
        less than equal to mid is less than k
            then increase the number. Otherwise 
            decrement the number and try to find a better answer.
        */
    if (count(nums, mid) < k) low = mid + 1;
    else high = mid;
  }

  return low;
}

/*
Time Complexity: O(N * log(K)), The approach efficiently maintains a container of the K smallest elements while iterating through the array, ensuring a time complexity of O(N * log(K)), where N is the number of elements in the array.
Auxiliary Space: O(K)
*/
function kthSmallest(arr, K) {
  // Create a max heap (priority queue)
  let pq = new MaxHeap();

  // Iterate through the array elements
  for (let i = 0; i < arr.length; i++) {
    // Push the current element onto the max heap
    pq.push(arr[i]);

    // If the size of the max heap exceeds K, remove the largest element
    if (pq.size() > K) pq.pop();
  }

  // Return the Kth smallest element (top of the max heap)
  return pq.top();
}
// MaxHeap class definition
class MaxHeap {
  constructor() {
    this.heap = [];
  }

  push(val) {
    this.heap.push(val);
    this.heapifyUp(this.heap.length - 1);
  }

  pop() {
    if (this.heap.length === 0) {
      return null;
    }
    if (this.heap.length === 1) {
      return this.heap.pop();
    }

    const root = this.heap[0];
    this.heap[0] = this.heap.pop();
    this.heapifyDown(0);

    return root;
  }

  top() {
    if (this.heap.length === 0) {
      return null;
    }
    return this.heap[0];
  }

  size() {
    return this.heap.length;
  }

  heapifyUp(index) {
    while (index > 0) {
      const parentIndex = Math.floor((index - 1) / 2);
      if (this.heap[parentIndex] >= this.heap[index]) {
        break;
      }
      this.swap(parentIndex, index);
      index = parentIndex;
    }
  }

  heapifyDown(index) {
    const leftChildIndex = 2 * index + 1;
    const rightChildIndex = 2 * index + 2;
    let largestIndex = index;

    if (
      leftChildIndex < this.heap.length &&
      this.heap[leftChildIndex] > this.heap[largestIndex]
    ) {
      largestIndex = leftChildIndex;
    }

    if (
      rightChildIndex < this.heap.length &&
      this.heap[rightChildIndex] > this.heap[largestIndex]
    ) {
      largestIndex = rightChildIndex;
    }

    if (index !== largestIndex) {
      this.swap(index, largestIndex);
      this.heapifyDown(largestIndex);
    }
  }

  swap(i, j) {
    [this.heap[i], this.heap[j]] = [this.heap[j], this.heap[i]];
  }
}

/* Counting Sort
Time Complexity:O(N + max_element), where max_element is the maximum element of the array.
Auxiliary Space: O(max_element)
*/
function kthSmallest(arr, k) {
  // First, find the maximum element in the array
  let maxElement = arr[0];
  for (let i = 1; i < arr.length; i++) {
    if (arr[i] > maxElement) {
      maxElement = arr[i];
    }
  }

  // Create an array to store the frequency of each element in the input array
  let freq = new Array(maxElement + 1).fill(0);
  for (let i = 0; i < arr.length; i++) {
    freq[arr[i]]++;
  }

  // Keep track of the cumulative frequency of elements in the input array
  let count = 0;
  for (let i = 0; i <= maxElement; i++) {
    if (freq[i] !== 0) {
      count += freq[i];
      if (count >= k) {
        // If we have seen k or more elements, return the current element
        return i;
      }
    }
  }
  return -1; // kth smallest element not found
}
