
class Solution {
    static bool mycomp(vector<int>& v1, vector<int>& v2){
        if(v1[0]==v2[0])
            return v2[1]<v1[1];
            
        return v1[0]<v2[0];
    }
    int solve(int ind,int p,vector<vector<int>>&arr,vector<vector<int>>&dp)
    {
        if(ind>=arr.size())
          {  return 0;}
        if(dp[ind][p+1]!=-1)
        {
            return dp[ind][p+1];
        }
        int op1=0,op2=0;
        if(p ==-1 || arr[ind][0]>arr[p][0]&&arr[ind][1]>arr[p][1])
        {
           op1=(1+solve(ind+1,ind,arr,dp));
        }
        
        op2=solve(ind+1,p,arr,dp);
        dp[ind][p+1]=max(op1,op2);
        return dp[ind][p+1];
    }
public:
    int maxEnvelopes(vector<vector<int>>&arr) {
        int n=arr.size();
        if(n==1)
            return 1;
        sort(arr.begin(),arr.end(),mycomp);
//         vector<int>dp(n+2,1);
//         int ans=1;        
//         for(int i=1;i<=n;i++)
//         {
//             for(int j=1;j<i;j++)
//             {
//                 if(arr[i-1][0]>arr[j-1][0] && arr[i-1][1]>arr[j-1][1])
//                 {
//                     dp[i]=max(dp[i],1+dp[j]);
                   
//                 }
//                  ans=max(ans,dp[i]);
//             }
//         }
//         return ans;
        vector<int>dp;
        for(int i=0;i<n;i++)
        {
            int h=arr[i][1];
            int ind = lower_bound(dp.begin(),dp.end(),h)-dp.begin();
            if(ind==dp.size())
            {
                dp.push_back(h);
            }else
                 dp[ind]=h;
        
        }
        return dp.size();
        
        //  vector<vector<int>>dp(n+2,vector<int>(n+2,-1));
      //  return solve(0,-1,arr,dp);
        
    }
};