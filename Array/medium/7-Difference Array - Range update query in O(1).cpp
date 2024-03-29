/*
An efficient solution is to use difference array. After all queries you can return original array from it. Time complexity of update here is improved to O(1). Note that printArray() still takes O(n) time. 
Time complexity: O(n)
Auxiliary Space: O(n)
*/
// ---------------------CODE-----------------------
function initializeDiffArray( A){
    let n = A.length;
 
    // We use one extra space because
    // update(l, r, x) updates D[r+1]
    let D= [];
 
    D[0] = A[0], D[n] = 0;
    for (let i = 1; i < n; i++)
        D[i] = A[i] - A[i - 1];
    return D;
}
 
// Does range update
function update(D, l, r, x){
    D[l] += x;
    D[r + 1] -= x;
    return D;
}
 
// Prints updated Array
function printArray( A, D){
    for (let i = 0; i < A.length; i++) {
        if (i == 0)
            A[i] = D[i];
 
        // Note that A[0] or D[0] decides
        // values of rest of the elements.
        else
            A[i] = D[i] + A[i - 1];
 
        document.write( A[i]+ " ");
    }
    document.write("<br>");
}
 
// Driver Code
// Array to be updated
let A = [ 10, 5, 20, 40 ];
 
// Create and fill difference Array
let D = initializeDiffArray(A);
 
// After below update(l, r, x), the
// elements should become 20, 15, 20, 40
D = update(D, 0, 1, 10);
printArray(A, D);
 
// After below updates, the
// array should become 30, 35, 70, 60
D = update(D, 1, 3, 20);
D = update(D, 2, 2, 30);
printArray(A, D);
 

/*

*/
// ---------------------CODE-----------------------

