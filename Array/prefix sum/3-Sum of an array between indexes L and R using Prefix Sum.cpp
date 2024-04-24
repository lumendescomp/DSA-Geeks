/*
Time Complexity: O(N)
Auxiliary Space: O(N)
*/
// ---------------------CODE-----------------------
// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N];
int pf[N];


// Driver code
int main()
{
	int n = 6;
	int a[] = { 3, 6, 2, 8, 9, 2 };
	//Calculating prefix sum
	pf[0] = a[0];
	for (int i = 1; i < n; i++) {
		pf[i] = pf[i - 1] + a[i];
	}

	int q = 4;
	//Creating a 2D vector to store queries and display output
	vector<vector<int> > query
		= { { 2, 3 }, { 4, 6 }, { 1, 5 }, { 3, 6 } };
	
	//Printing sum from Queries
	for (int i = 0; i < q; i++) {
		int l = query[i][0], r = query[i][1];
		if (r > n || l < 1) {
			cout << "Please input in range 1 to " << n
				<< endl;
			continue;
		}
		if (l == 1)
			cout << pf[r - 1] << endl;
		else
			cout << pf[r - 1] - pf[l - 2] << endl;
	}
	return 0;
}


/*

*/
// ---------------------CODE-----------------------

