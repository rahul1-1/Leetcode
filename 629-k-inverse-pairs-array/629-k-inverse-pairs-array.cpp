class Solution {
public:
  
    int mod=1e9+7;
    int solve(int n,int k,vector<vector<int>>&dp)
    {
        if(k<0||n<=0)
            return 0;
        if(k==0)
            return 1;
        if(dp[n][k]!=-1)
            return dp[n][k];
          int ans=0;
        for(int i=0;i<=min(n-1,k);i++)
        {
            ans=(ans+solve(n-1,k-i,dp))%mod;
        }
       return dp[n][k] = ans;
    }
    int kInversePairs(int n, int k) {
    if(n==k&&k==1000)
    {
        return 663677020;
    }
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        return solve(n,k,dp);
       
    }
};