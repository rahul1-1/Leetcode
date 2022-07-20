class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>>ind(26);
        
        for(int i=0;i<s.length();i++)
        {
            ind[s[i]-'a'].push_back(i);
        }
        int cnt=0;

        for(auto &w:words)
        {
            bool flag=true;
            int lastInd=-1;
            for(auto &ch:w)
            {
               auto it=upper_bound(ind[ch-'a'].begin(),ind[ch-'a'].end(),lastInd);
                if(it==ind[ch-'a'].end())
                {
                    flag=false;
                    break;
                }else{
                    lastInd=*it;
                }
            }
            if(flag)
            {
                cnt++;
            }
        }
        return cnt;
    }
};