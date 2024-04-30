/*
Time Complexity: O(1).
Auxiliary Space: O(1).
*/
// ---------------------CODE-----------------------
int main() 
{ 
    int x = 10, y = 5; 
    // Code to swap 'x' (1010) and 'y' (0101) 
    x = x ^ y; // x now becomes 15 (1111) 
    y = x ^ y; // y becomes 10 (1010) 
    x = x ^ y; // x becomes 5 (0101) 
    cout << "After Swapping: x =" << x << ", y=" << y; 
    return 0; 
}
/*
Time Complexity: O(1).
Auxiliary Space: O(1).
*/
// ---------------------CODE-----------------------
int main() 
{ // NOTE - for this code to work in a generalised sense, y 
// !- 0 to prevent zero division 
	int x = 10, y = 5; 

	if (y == 0) { 
		y = x; 
		x = 0; 
	} 
	else if (x == 0) { 
		x = y; 
		y = 0; 
	} 
	// Code to swap 'x' and 'y' 
	else { 
		x = x * y; // x now becomes 50 
		y = x / y; // y becomes 10 
		x = x / y; // x becomes 5 
	} 
	cout << "After Swapping: x =" << x << ", y=" << y; 
} 
/*
Time Complexity: O(1)
Auxiliary Space: O(1)
*/
// ---------------------CODE-----------------------
int main() 
{ 
    int x = 10, y = 5; 
  
    // Code to swap 'x' and 'y' 
    x = x + y; // x now becomes 15 
    y = x - y; // y becomes 10 
    x = x - y; // x becomes 5 
    cout << "After Swapping: x =" << x << ", y=" << y; 
} 
