/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
// ---------------------CODE-----------------------
bool isPrime(int n){
    if(n<= 0){
        return false;
    }
    for (int i = 2; i < n; i++)
    {
        if(n%i == 0){
            return false;
        }
    }

    return true;
}

/*
Time Complexity: O(√n)
Auxiliary Space: O(1)
*/
// ---------------------CODE-----------------------
bool isPrime(int n) 
{ 
    // Corner case 
    if (n <= 1) 
        return false; 
  
    // Check from 2 to square root of n 
    for (int i = 2; i <= sqrt(n); i++) 
        if (n % i == 0) 
            return false; 
  
    return true; 
} 

/*
Time Complexity: O(√n)
Auxiliary Space: O(1)
*/
// ---------------------CODE-----------------------
bool isPrime(int n) 
{ 
    if (n == 2 || n == 3) 
        return true; 
  
    if (n <= 1 || n % 2 == 0 || n % 3 == 0) 
        return false; 
  
    // To check through all numbers of the form 6k ± 1 
    for (int i = 5; i * i <= n; i += 6) { 
        if (n % i == 0 || n % (i + 2) == 0) 
            return false; 
    } 
  
    return true; 
} 

/*

*/
// ---------------------CODE-----------------------

