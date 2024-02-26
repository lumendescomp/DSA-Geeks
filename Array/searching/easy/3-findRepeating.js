//Given an array of integers arr[], The task is to find the index of first repeating element in it i.e. the element that occurs more than once and whose index of the first occurrence is the smallest.

let array = [1, 3, 7, 7, 3, 9];

//Solution should be O(n) - O(n)
function findRepeating(array) {
  let tracker = new Map();
  array.forEach((el) => {
    if (tracker.has(el)) {
      tracker.set(el, tracker.get(el) + 1);
    } else {
      tracker.set(el, 1);
    }
  });

  //Usar forEach não funciona!
  for (let i = 0; i < array.length; i++) {
    if (tracker.get(array[i]) > 1) {
      return [array[i], i];
    }
  }

  return [-1, -1];
}

//JavaScript
function firstRepeatingElementIndex(arr) {
  let seen = new Map();

  for (let i = 0; i < arr.length; i++) {
    if (seen.has(arr[i])) {
      return seen.get(arr[i]);
    }
    seen.set(arr[i], i);
  }

  return -1; // return -1 if there are no repeating elements
}

//C++
/* 
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int firstRepeatingElementIndex(const vector<int>& arr) {
    unordered_map<int, int> elementIndexMap;

    int minIndex = INT_MAX;
    for (int i = arr.size() - 1; i >= 0; --i) {
        if (elementIndexMap.find(arr[i]) != elementIndexMap.end()) {
            minIndex = i;
        } else {
            elementIndexMap[arr[i]] = i;
        }
    }

    // If minIndex is not changed, there are no repeating elements
    return (minIndex == INT_MAX) ? -1 : minIndex;
}

int main() {
    vector<int> arr = {10, 5, 3, 4, 3, 5, 6};
    int index = firstRepeatingElementIndex(arr);
    
    if (index != -1) {
        cout << "The first repeating element is at index: " << index << endl;
    } else {
        cout << "There are no repeating elements." << endl;
    }

    return 0;
}

*/
