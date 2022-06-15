class Solution {
public:
    bool static comp(string &a,string &b )
    {
        if(a.length()<b.length())
            return true;
        return false;
    }
    int longestStrChain(vector<string>&arr) {
        sort(arr.begin(),arr.end(),comp);
        unordered_map<string,int>mp;
        int res=0;
        for(auto x:arr)
        {
            for(int i=0;i<x.length();i++)
            {
                string str=x.substr(0,i)+x.substr(i+1);
                mp[x]=max(mp[x],mp.find(str)==mp.end()?1:mp[str]+1);
            }
            res=max(res,mp[x]);
        }
        return res;
    }
};