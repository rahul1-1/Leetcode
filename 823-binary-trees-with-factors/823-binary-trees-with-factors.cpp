class Solution {
public:
    int const mod=1e9+7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        unordered_map<int,unsigned long long>mp;
        int ans=0;
        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]]=1;
            for(int j=0;j<i;j++)
            {
                if(arr[i]%arr[j]==0)
               { 
                    mp[arr[i]]+= (mp[arr[j]]*(mp[arr[i]/arr[j]]))%mod;
                    mp[arr[i]]%mod;
               }
            }
            ans=(ans+mp[arr[i]])%mod;
        }
        
        return ans;
    }
};