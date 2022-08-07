class Solution {
public:
    unordered_map<string ,int>dp;
    int mod=1e9+7;
    
    long long solve(int n,char pc)
    {
        if(n==0)
            return 1;
        string s='$'+to_string(n)+pc;
        if(dp.find(s)!=dp.end())
            return dp[s];
        long long tot=0;
        switch(pc)
        {
            case 'a':tot =(solve(n-1,'e'))%mod;
        break;
        case 'e':tot=(solve(n-1,'a') + solve(n-1,'i'))%mod;
        break;
        case 'i': tot=(solve(n-1,'a')+solve(n-1,'e')+solve(n-1,'o')+solve(n-1,'u'))%mod;
            break;
        case 'o':tot=(solve(n-1,'i')+solve(n-1,'u'))%mod;
        break;
        case 'u':tot=(solve(n-1,'a'))%mod;
        break;
        }
        dp[s]=tot;
        return tot;
    }
    
    int countVowelPermutation(int n) {
        long long tot=0;
        char c[]={'a','e','i','o','u'};
        for(auto x:c)
        {
            tot=(tot+solve(n-1,x))%mod;
        }
        return (int)tot;
    }
};