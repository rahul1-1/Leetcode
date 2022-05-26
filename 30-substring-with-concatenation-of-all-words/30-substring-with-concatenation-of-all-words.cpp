class Solution {
public:
    unordered_map<string,int>mp;
    bool check(int j,string &s,int m,int len)
    {
        int t=len;
         
        unordered_map<string ,int>cmp;
        while(t--)
        {
         string st=s.substr(j,m);
            j+=m;
            cmp[st]++;
          //  cout<<" "<<st<<" ";
        }
       //cout<<endl;
        if(cmp==mp)
            return true;
        return false;
    }
    vector<int> findSubstring(string s, vector<string>&w) {
        int n=s.length();
        int len=w[0].length();
        for(auto &x:w)
        {
            mp[x]++;
        }
        int m=w.size();
        vector<int>ans;
        
        for(int i=0;i<=n-(len*m);i++)
        {
           
            if(check(i,s,len,m))
            {
               
                ans.push_back(i);
            }
            
        }
        return ans;
    }
};