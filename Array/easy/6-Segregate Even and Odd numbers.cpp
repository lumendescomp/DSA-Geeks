/*
Time Complexity: O(n)
Auxiliary Space: O(1*/
void swap(int *a, int *b);

void segregateEvenOdd(int arr[], int size)
{
    /* Initialize left and right indexes */
    int left = 0, right = size-1;
    while (left < right)
    {
        /* Increment left index while we see 0 at left */
        while (arr[left] % 2 == 0 && left < right)
            left++;
 
        /* Decrement right index while we see 1 at right */
        while (arr[right] % 2 == 1 && left < right)
            right--;
 
        if (left < right)
        {
            /* Swap arr[left] and arr[right]*/
            swap(&arr[left], &arr[right]);
            left++;
            right--;
        }
    }
}

/*
Time Complexity : O(n/2) 
Auxiliary Space : O(n)
*/
// ---------------------CODE-----------------------
// CPP code to segregate even odd
// numbers in an array
// Function to segregate even odd numbers
void arrayEvenAndOdd(int arr[], int n) {

int b[n]; // To store result
int k = 0, l = n - 1, i, j;
for (i = 0, j = n - 1; i < j; i++, j--) {

	if (arr[i] % 2 == 0) {
	b[k] = arr[i];
	k++;
	} else {
	b[l] = arr[i];
	l--;
	}

	if (arr[j] % 2 == 0) {
	b[k] = arr[j];
	k++;
	} else {
	b[l] = arr[j];
	l--;
	}
}

// for i == j in case of odd length
b[i] = arr[i];

// Printing segregated array
for (int i = 0; i < n; i++) 
	cout << b[i] << " "; 
}

// Driver code
int main() {
int arr[] = {1, 3, 2, 4, 7, 6, 9, 10};
int n = sizeof(arr) / sizeof(int);
arrayEvenAndOdd(arr, n);
return 0;
}


/*

*/
// ---------------------CODE-----------------------


