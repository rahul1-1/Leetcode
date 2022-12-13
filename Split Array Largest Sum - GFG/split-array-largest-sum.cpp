//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    bool check(int arr[],int n,int k, int mid)
    {
        long long sum=0;
        int cnt=1;
        for(int i=0;i<n;i++)
        {
            if(arr[i]>mid)
            return true;
            if(sum+arr[i]>mid)
            {
                sum=arr[i];
                cnt++;
            
            }else{
                sum+=arr[i];
            }
        }
        if(cnt<=k)
        return false;
        
        return true;
    }
    int splitArray(int arr[] ,int n, int k) {
        // code here
        long long sum = 0;
        for (int i=0;i<n;i++)
        {
            sum+=arr[i];
        }
        if(k==1)
        return sum;
        
        long l=1,r=sum;
        int ans=0;
        while(l<r)
        {
            long mid=(l+r)/2;
            if(check(arr,n,k,mid)==false)
            {
                ans=mid;
                r=mid;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends