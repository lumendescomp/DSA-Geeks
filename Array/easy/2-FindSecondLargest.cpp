//Given an array of integers, our task is to write a program that efficiently finds the second-largest element present in the array.
/* 
Time Complexity: O(n)
Auxiliary space: O(1)
*/
 
int secondLargest(int arr[], int n) {
    int first = 0, second = -1;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[first]) {
            second = first;
            first = i;
        }
        else if (arr[i] < arr[first]) {
            if (second == -1 || arr[second] < arr[i])
                second = i;
        }
    }
    return second;
}
