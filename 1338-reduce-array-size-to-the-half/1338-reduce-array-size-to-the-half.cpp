class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int N=100005;
        vector<int>mp(N,0);
        vector<int>v;
        for(auto &x:arr)
            mp[x]++;
        int n=arr.size();
        sort(mp.begin(),mp.end());
        int cnt=n/2;
        int i;
        for(i=N-1;i>=0&&cnt>0;i--)
        {
            cnt-=mp[i];
        }
       return N-i-1;
        
    }
};