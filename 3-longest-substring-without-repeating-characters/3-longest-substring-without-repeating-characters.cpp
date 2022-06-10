class Solution {
public:
    int lengthOfLongestSubstring(string s) {
         int n=s.length();
        map<char,int>mp;
        int cnt=0;
        int curr=0;
      int j=0,i;
        for( i=0;i<n;i++)
        {
            if(mp.find(s[i])!=mp.end())
                j=max(mp[s[i]]+1,j);
            
            mp[s[i]]=i;
            cnt=max(cnt,i-j+1);
        }
      
        return cnt;
    }
};