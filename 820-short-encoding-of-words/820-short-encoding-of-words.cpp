class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> s;
        
        for(string word: words)
            s.insert(word);
        
        for(string word: words)
            for(int i=1;i<word.length();i++)
                s.erase(word.substr(i));
        
        int ans(0);
        
        for(string word: s)
            ans += word.length()+1;
        
        return ans;
    }
};
static int fastio = []() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
