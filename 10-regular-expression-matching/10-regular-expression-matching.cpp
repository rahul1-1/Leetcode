class Solution {
public:
    int n=0,m=0;
    bool check(int i, int j, string &p, string &s,  vector<vector<int>>&dp ){
      
        if(i>=n && j>=m)
        {
            
            return true;
        }
        if(j>=m)
           {
           
            return false;
        }
        bool ans= i<n && (p[j]==s[i] or p[j]=='.');
        if(j+1<m && (p[j+1]=='*'))
        {
            
           return  check(i,j+2,p,s,dp) || (ans && check(i+1,j,p,s,dp));
        }else if(ans)
        {
           
           return  check(i+1,j+1,p,s,dp);
        }
        return false;
    }
    
    bool isMatch(string s, string p) {
                
         m= p.length();
         n= s.length();
        vector<vector<int>>dp (n, vector<int>(m, -1));
        return check(0, 0, p, s,dp);
        
    }
};