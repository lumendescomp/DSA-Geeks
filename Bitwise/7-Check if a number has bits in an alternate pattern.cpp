/*
Time Complexity: O(1)
Auxiliary Space: O(1)
*/
// ---------------------CODE-----------------------
static bool allBitsAreSet(int n)
{
    // if true, then all bits are set
    if (((n + 1) & n) == 0)
        return true;
 
    // else all bits are not set
    return false;
}
 
// Function to check if a number
// has bits in alternate pattern
bool bitsAreInAltOrder(unsigned int n)
{
    unsigned int num = n ^ (n >> 1);
 
    // To check if all bits are set in 'num'
    return allBitsAreSet(num);
}

/*

*/
// ---------------------CODE-----------------------

