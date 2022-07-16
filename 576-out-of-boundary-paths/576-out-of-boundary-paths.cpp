class Solution {
public:
     int mod=1e9+7;
    int dp[51][51][51];
    int solve(int m,int n,int i,int j,int move)
    {
        if(i<0 ||j<0 ||i>=m || j>=n)
        {
            return 1;
        }
        if(move<=0)
            return 0;
        if(dp[i][j][move]!=-1)
        {
            return dp[i][j][move];
        }
       dp[i][j][move]= ( (solve(m,n,i-1,j,move-1) + solve(m,n,i+1,j,move-1))%mod + (solve(m,n,i,j-1,move-1) + solve(m,n,i,j+1,move-1))%mod)%mod;
        return dp[i][j][move];
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        
        memset(dp,-1,sizeof dp);
       return solve(m,n,startRow,startColumn,maxMove);
       
       
    }
};