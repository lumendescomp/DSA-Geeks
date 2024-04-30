/*
Time Complexity: O(n) 
Auxiliary Space: O(1)
*/
// ---------------------CODE-----------------------
vector<int> get2NonRepeatingNos(vector<int>& nums)
{
    long long int diff = 0;
    for (auto i : nums) {
        diff = i ^ diff;
    }

    // Get its last set bit
    diff &= -diff;

    // Pass 2:
    vector<int> rets = {
        0, 0
    };
    for (int num : nums) {
        if ((num & diff) == 0) { 
            rets[0] ^= num;
        }
        else { // the bit is set
            rets[1] ^= num;
        }
    }

    if (rets[0] > rets[1]) {
        swap(rets[0], rets[1]);
    }

    return rets;
}
