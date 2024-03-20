/*
Time Complexity: O(n)
Auxiliary Space: O(1)
*/
// ---------------------CODE-----------------------
void printLeaders(int arr[], int size)
{
    int max_from_right = arr[size - 1];
 
    /* Rightmost element is always leader */
    printf("%d ", max_from_right);
 
    for (int i = size - 2; i >= 0; i--) {
        if (max_from_right < arr[i]) {
            max_from_right = arr[i];
            printf("%d ", max_from_right);
        }
    }
}

/*

*/
// ---------------------CODE-----------------------

