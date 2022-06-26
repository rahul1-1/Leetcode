class Solution {
public:
    int maxScore(vector<int>&arr, int k) {
        int n=arr.size();
        int ls[k+1];
        int rs[k+1];
        ls[0]=0;
        rs[0]=0;
        for(int i=0;i<k;i++)
            ls[i+1]=arr[i]+ls[i];
        for(int i=0;i<k;i++)
        {
            rs[i+1]=arr[n-i-1]+rs[i];
        }
        int res=0;
        for(int i=0;i<=k;i++)
        {
            res=max(res,(ls[i]+rs[k-i]));
        }
        return res;
            
    }
};