/*Time Complexity: O(2^n)
Auxiliary Space: O(n) */
#include <bits/stdc++.h> 
using namespace std; 
  
void findPowerSet(char* s, vector<char> &res, int n){ 
    if (n == 0) { 
        for (auto i: res)  
            cout << i; 
        cout << "\n"; 
        return; 
            
    } 
        res.push_back(s[n - 1]); 
        findPowerSet(s, res, n - 1); 
        res.pop_back();                     
        findPowerSet(s, res, n - 1); 
}  
/* Time Complexity: O(2n)
Auxiliary Space: O(n), For recursive call stack*/
#include <bits/stdc++.h>
using namespace std;
 
// str : Stores input string
// curr : Stores current subset
// index : Index in current subset, curr
void powerSet(string str, int index = 0, string curr = "")
{
    int n = str.length();
 
    // base case
    if (index == n) {
        cout << curr << endl;
        return;
    }
 
    // Two cases for every character
    // (i) We consider the character
    // as part of current subset
    // (ii) We do not consider current
    // character as part of current
    // subset
    powerSet(str, index + 1, curr + str[index]);
    powerSet(str, index + 1, curr);
}
/* */