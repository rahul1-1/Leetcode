//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int solve(int ind, int *arr, int n,vector<int>&dp)
	{
	    if(ind>=n)
	    return 0;
	    
	    if(dp[ind]!=-1)
	    {
	        return dp[ind];
	    }
	    int ans=0;
	    ans+=max(arr[ind]+solve(ind+2,arr,n,dp),solve(ind+1,arr,n,dp));
	    dp[ind]=ans;
	    return ans;
	}
	int findMaxSum(int *arr, int n) {
	    // code here
	    vector<int>dp(n+1,-1);
	    return solve(0,arr,n,dp);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends