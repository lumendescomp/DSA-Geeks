//You are given n activities with their start and finish times. Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time.
/*
Time Complexity: O(N log N), If input activities may not be sorted. It takes O(n) time when it is given that input activities are always sorted.
Auxiliary Space: O(1)
*/
// ---------------------CODE-----------------------
struct Activity { 
    int start, finish; 
}; 
  
bool activityCompare(Activity s1, Activity s2) 
{ 
    return (s1.finish < s2.finish); 
} 
void printMaxActivities(Activity arr[], int n) 
{ 
    // Sort jobs according to finish time 
    sort(arr, arr + n, activityCompare); 
  
    cout << "Following activities are selected :\n"; 
  
    // The first activity always gets selected 
    int i = 0; 
    cout << "(" << arr[i].start << ", " << arr[i].finish 
         << ")"; 
  
    for (int j = 1; j < n; j++) { 
        if (arr[j].start >= arr[i].finish) { 
            cout << ", (" << arr[j].start << ", "
                 << arr[j].finish << ")"; 
            i = j; 
        } 
    } 
}

/*
How does Greedy Choice work for Activities sorted according to finish time? 
Let the given set of activities be S = {1, 2, 3, …n}, and activities are sorted by finish time. The greedy choice is to always pick activity 1. How come activity 1 always provides one of the optimal solutions?

 We can prove it by showing that if there is another solution B with the first activity other than 1, then there is also a solution A of the same size as activity 1 as the first activity. Let the first activity selected by B be k, then there always exist A = {B – {k}} U {1}.

Note: The activities in B are independent and k has the smallest finishing time among all. Since k is not 1, finish(k) >= finish(1))
*/
