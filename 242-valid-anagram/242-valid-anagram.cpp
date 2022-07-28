class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())
            return false;
        vector<int>a(26,0),b(26,0);
        for(int i=0;i<t.length();i++)
        {
            a[s[i]-'a']++;
            b[t[i]-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            if(a[i]!=b[i])
               { return false;}
        }
        return true;
    }
};