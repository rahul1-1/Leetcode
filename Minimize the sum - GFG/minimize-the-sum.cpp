//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int minimizeSum(int N, vector<int> arr) {
        // code here
        int ans=0;
        priority_queue<int, vector<int>, greater<int>> heap;
    // Insert all the elements of array into heap
    for (int x : arr) 
        heap.push(x);

    // Keep removing two minimum elements from heap and add the sum until only one element left
    while (heap.size() > 1) {
        // Extract the minimum element from heap
        int smallest = heap.top();
        heap.pop();
        // Extract the second minimum element from heap
        int secondSmallest = heap.top();
        heap.pop();
        // Add the sum of two extracted elements and store in ans
        ans += (smallest + secondSmallest);
        // Insert the sum of two extracted element into heap
        heap.push(smallest + secondSmallest);
    }
    // return an;
    return ans;
    }
};

//{ Driver Code Starts.

int main() {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
            cin>>arr[i];
        Solution obj;
        cout << obj.minimizeSum(n, arr) << "\n";
    }
}
// } Driver Code Ends