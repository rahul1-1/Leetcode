#include<bits/stdc++.h>
class Solution {
    string solve(string &s)
    {
        unordered_map<char,int>mp;
        string ns="";
        for(int i=0;i<s.length();i++)
        {
       
            if(mp.find(s[i])==mp.end())
            {
                mp[s[i]]=i;
            }
            ns+=to_string(mp[s[i]]);
        }
        return  ns;
    }
public:
    
    vector<string> findAndReplacePattern(vector<string>& words, string p) {
        
       vector<string>ans;
        string ps=solve(p);
        for(auto& w:words)
        {
            if(ps==solve(w))
            {
                ans.push_back(w);
            }
        }
        return ans;
    }
};