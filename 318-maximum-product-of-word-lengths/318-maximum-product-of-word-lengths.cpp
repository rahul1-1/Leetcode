class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int>bit;
        for(int k=0;k<words.size();k++)
        {
            string s=words[k];
            int num=0;
            for(int i=0;i<s.length();i++)
            {
                
                int j=s[i]-'a';
                num|=(1<<j);
            }
            bit.push_back(num);
        }
        int ans=0;
        for(int i=0;i<bit.size();i++)
        {
            for(int j=0;j<bit.size();j++)
            {
                if((bit[i]&bit[j])==0)
                {
                    int l=(words[i].length())*(words[j].length());
                    ans=max(ans,l);
                }
            }
        }
        return ans;
    }
};