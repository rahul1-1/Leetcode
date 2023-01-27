class Solution {
public:
   vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> result;
        if(words.empty()) return result; 
        auto mycomp = [&](const string& str1, const string& str2){return str1.size() < str2.size();};
        sort(words.begin(), words.end(), mycomp);
        unordered_set<string> mp;
        for(auto& word: words) {
            string path = "";
            if(dfs(word, 0, path, 0, mp)) result.push_back(word); 
            else mp.insert(word); 
        }
        return result;
    }
    
private:
    bool dfs(string& word, int pos, string& path, int nb, unordered_set<string>& mp) {
        if(pos == word.size()) {
            if(mp.find(path) != mp.end() && nb > 0) return true;
            else return false;
        }
        path.push_back(word[pos]);
        if(mp.find(path) != mp.end()) {
            string temp = "";
            if(dfs(word, pos+1, temp, nb+1, mp)) return true;
        }
        if(dfs(word, pos+1, path, nb, mp)) return true;
        else return false;
    }
};