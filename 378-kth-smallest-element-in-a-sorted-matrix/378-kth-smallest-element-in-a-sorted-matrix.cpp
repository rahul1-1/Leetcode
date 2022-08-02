class Solution {
public:
    int kthSmallest(vector<vector<int>>& arr, int k) {
        int l=arr[0][0];
        int n=arr.size();
        int m=arr[0].size();
        int r=arr[n-1][m-1];
        int ans;
        while(l<=r)
        {
            int mid=(l+r)/2;
            int cnt=0;
            for(int i=0;i<n;i++)
            {
                cnt+=upper_bound(arr[i].begin(),arr[i].end(),mid)-arr[i].begin();
            }
            if(cnt<k)
            {
                l=mid+1;
            }
            else{
                ans=mid;
                r=mid-1;
            }
        }
        return ans;
    }
};