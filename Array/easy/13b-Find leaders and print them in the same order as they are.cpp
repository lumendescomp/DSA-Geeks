/*
Time Complexity: O(n)
Auxiliary Space: O(n)
*/
// ---------------------CODE-----------------------
void printLeaders(int arr[], int size)
{
      /* create stack to store leaders*/
      stack<int> sk;
      sk.push(arr[size-1]);
     
    for (int i = size-2; i >= 0; i--)
    {
        if(arr[i] >= sk.top())
        {          
            sk.push(arr[i]);
        }
    }   
     
      /* print stack elements*/
      /* run loop till stack is not empty*/
      while(!sk.empty()){      
        cout<<sk.top()<<" ";
          sk.pop();
    }
}

/*

*/
// ---------------------CODE-----------------------

