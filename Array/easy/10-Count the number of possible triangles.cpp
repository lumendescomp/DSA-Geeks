/*
Time complexity: O(N2).  As two nested loops are used, overall iterations in comparison to the above method reduces greatly.
Auxiliary Space: O(1).  As no extra space is required, Auxiliary Space is constant
*/
// ---------------------CODE-----------------------
void CountTriangles(vector<int> A) 
{ 
  
    int n = A.size(); 
  
    sort(A.begin(), A.end()); 
  
    int count = 0; 
  
    for (int i = n - 1; i >= 1; i--) { 
        int l = 0, r = i - 1; 
        while (l < r) { 
            if (A[l] + A[r] > A[i]) { 
  
                // If it is possible with a[l], a[r] 
                // and a[i] then it is also possible 
                // with a[l+1]..a[r-1], a[r] and a[i] 
                count += r - l; 
  
                // checking for more possible solutions 
                r--; 
            } 
            else
  
                // if not possible check for 
                // higher values of arr[l] 
                l++; 
        } 
    } 
    cout << "No of possible solutions: " << count; 
} 

/*

*/
// ---------------------CODE-----------------------

