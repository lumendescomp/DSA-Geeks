/*
Time Complexity: O(K) where K is the number of bits
Auxiliary Space: O(1)
*/
// ---------------------CODE-----------------------
int countSetBits(int n)
{
    int count = 0;
    while (n > 0) {
        count++;
        n &= (n - 1);
    }
    return count;
}

/*
Time Complexity: O(K) where K is the number of bits
Auxiliary Space: O(1)
*/
// ---------------------CODE-----------------------
int countFlips(int a, int b)
{
 
    // initially flips is equal to 0
    int flips = 0;
 
    // & each bits of a && b with 1
    // and store them if t1 and t2
    // if t1 != t2 then we will flip that bit
 
    while (a > 0 || b > 0) {
 
        int t1 = (a & 1);
        int t2 = (b & 1);
 
        if (t1 != t2) {
            flips++;
        }
        // right shifting a and b
        a >>= 1;
        b >>= 1;
    }
 
    return flips;
}
