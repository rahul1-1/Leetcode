//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> leastPrimeFactor(int n) {
        // code here
        vector<int>pri(n+1,0);
        pri[0]=0;
        pri[1]=1;
        pri[2]=2;
        for(int i=3;i<=n;i+=2)
        {
            if(pri[i]==0)
            {
                for(int j=i;j<=n;j+=i)
                {
                    if(pri[j]==0)
                    pri[j]=i;
                }
            }
        }
        vector<int>ans(n+1,0);
        for(int i=1;i<=n;i++)
        {
            if(i%2)
            {
                ans[i]=pri[i];
            }else{
                ans[i]=2;
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
        int n;
        cin >> n;
        Solution ob;
        vector<int>ans = ob.leastPrimeFactor(n);
        for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
        cout<<endl;  
    }
    return 0;
}

// } Driver Code Ends