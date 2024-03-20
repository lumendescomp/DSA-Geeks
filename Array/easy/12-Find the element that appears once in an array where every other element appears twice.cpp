/*
The best solution is to use XOR. XOR of all array elements gives us the number with a single occurrence. The idea is based on the following two facts.

Time Complexity: O(n)
Auxiliary Space: O(1)
*/
// ---------------------CODE-----------------------
int findSingle(int ar[], int ar_size) 
{ 
    // Do XOR of all elements and return 
    int res = ar[0]; 
    for (int i = 1; i < ar_size; i++) 
        res = res ^ ar[i]; 
  
    return res; 
} 

/*
Time Complexity: O(nlogn)
Auxiliary Space: O(1)

Solução interessante: perceba que é os valores são verificados em pares. Logo, se mid não bater com mid ^ 1 (que deveria ser seu par) é pq do lado esquerdo tem um elemento sem seu respectivo par. 
*/
// ---------------------CODE-----------------------
int singleelement(int arr[], int n) 
{ 
    int low = 0, high = n - 2; 
    int mid; 
    while (low <= high) { 
        mid = (low + high) / 2; 
        if (arr[mid] == arr[mid ^ 1]) 
            low = mid + 1; 
        else
            high = mid - 1; 
    } 
    return arr[low]; 
} 
