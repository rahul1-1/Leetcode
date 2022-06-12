class Solution {
public:
    int maximumUniqueSubarray(vector<int>&arr) {
        int n=arr.size();
        vector<int>pre(n,0);
        pre[0]=arr[0];
        for(int i=1;i<n;i++)
            pre[i]=arr[i]+pre[i-1];
        
        map<int,int>mp;
        int l=0;
        int sum=INT_MIN;
        int curr=arr[0];
        mp[arr[0]]=0;
        for(int i=1;i<n;i++)
        {
            if(mp.find(arr[i])==mp.end())
            {
                curr+=arr[i];
            }
            else if(mp.find(i)!=mp.end()&&mp[arr[i]]<l)
            {
                curr+=arr[i];
            }
            else{
                int t=mp[arr[i]];
                l=max(l,t);
                curr=pre[i]-pre[l];
                
            
            }
            mp[arr[i]]=i;
          
            sum=max(sum,curr);
        }sum=max(sum,curr);
        return sum;
    }
};