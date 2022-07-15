// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    long long int minSum(int arr[], int n)
    {
        // Your code goes here
         sort(arr,arr+n);
    string s1="";
    string s2="";
    
    for(int i=0;i<n;i++)
    {
        if(i%2==0)
        s1+=to_string(arr[i]);
        else
        s2+=to_string(arr[i]);
    }
    long long  res =atoll(s1.c_str())+atoll(s2.c_str());
    return res;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n+1];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.minSum(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends