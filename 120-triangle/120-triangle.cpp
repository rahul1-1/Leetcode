class Solution {
public:
    int solve(vector<vector<int>>&arr ,int i,int j,int n,vector<vector<int>>&dp)
    {
        if(i==n-1)
            return arr[i][j];
        if(dp[i][j]!=-1)
            return dp[i][j];
        
 return dp[i][j] = min(arr[i][j]+solve(arr,i+1,j+1,n,dp),arr[i][j]+solve(arr,i+1,j,n,dp));
        
    }
    
    int minimumTotal(vector<vector<int>>&arr) {
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
     return solve(arr,0,0,n,dp);
    }
};
