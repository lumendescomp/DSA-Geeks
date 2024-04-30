/*
Time Complexity : O(sqrt(n)) 
Auxiliary Space : O(sqrt(n))
*/
// ---------------------CODE-----------------------
void printDivisors(int n) 
{ 
    // Vector to store half of the divisors 
    vector<int> v; 
    for (int i = 1; i <= sqrt(n); i++) { 
        if (n % i == 0) { 
  
            // check if divisors are equal 
            if (n / i == i) 
                printf("%d ", i); 
            else { 
                printf("%d ", i); 
  
                // push the second divisor in the vector 
                v.push_back(n / i); 
            } 
        } 
    } 
  
    // The vector will be printed in reverse 
    for (int i = v.size() - 1; i >= 0; i--) 
        printf("%d ", v[i]); 
} 

/*
Time complexity : O(sqrt(n)) 
Auxiliary Space : O(1) 
*/
// ---------------------CODE-----------------------
void printDivisors(int n) 
{ 
    int i; 
    for (i = 1; i * i < n; i++) { 
        if (n % i == 0) 
            cout<<i<<" "; 
    } 
    if (i - (n / i) == 1) { 
        i--; 
    } 
    for (; i >= 1; i--) { 
        if (n % i == 0) 
            cout<<n / i<<" "; 
    } 
} 
  
//The if condition between the two loops is used when corner factors in the loop’s condition have a difference of 1(for example- factors of 30 (5,6) here, 5 will be printed two times; to resolve that issue this step is required.