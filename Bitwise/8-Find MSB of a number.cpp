/*
Time Complexity: O(logn)
Auxiliary Space: O(1)
*/
// ---------------------CODE-----------------------
// Simple CPP program to find MSB number
// for given POSITIVE n.
int setBitNumber(int n)
{
    if (n == 0)
        return 0;
 
    int msb = 0;
    n = n / 2;
    while (n != 0) {
        n = n / 2;
        msb++;
    }
 
    return (1 << msb);
}