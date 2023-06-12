//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  int  solve(int i,int arr[],int n, vector<vector<int>>&dp)
  {
    if(i==0)
    {
        return arr[0]*n;
    }
    if(dp[i][n]!=-1)
    return dp[i][n];
    int notTake = solve(i-1,arr,n,dp);
    int take=INT_MIN;
    int rodLength = i+1;
    if(rodLength <= n)
    take = max(take, arr[i]+solve(i,arr,n-rodLength,dp));
    return  dp[i][n] = max(take,notTake);
  }
    int cutRod(int arr[], int n) {
        //code here
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(n-1,arr,n,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends