class Solution {
public:
    int solve(int i,int n,vector<int>&dy,vector<int>&ct,vector<int>&dp)
    {
        if(i>=n) return 0;  
        
        if(dp[i]>0) return dp[i];
        
        int op1=ct[0]+solve(i+1,n,dy,ct,dp);
        
        int k=i;
        for(;k<n;k++)
        {
            if(dy[k]>=dy[i]+7)
         {   break;}
        }
        int op2=ct[1]+solve(k,n,dy,ct,dp);
        
        for(;k<n;k++)
        {
            if(dy[k]>=dy[i]+30)
              {  break;}
        }
        int op3=ct[2]+solve(k,n,dy,ct,dp);
          dp[i] = min({op1,op2,op3});
        return min({op1,op2,op3});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int>dp(n,0);
         solve(0,n,days,costs,dp);
      
       
        return dp[0];
    }
};