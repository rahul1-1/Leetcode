//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  vector<long long int> countZero(int n, int k, vector<vector<int>>& arr){
      //Code Here
      long long int tot0=(n*n);
      vector<int>r(n+1,0);
      vector<int>c(n+1,0);
      long long int cr=0;
      long long int cc=0;
      vector<long long int>ans;
      for(auto &v:arr)
      {
          int x=v[0];
          int y=v[1];
          if(r[x]==0 &&c[y]==0)
          {
             long long int temp = tot0-(1ll*2*n-1); 
             tot0=temp+cr+cc;
             r[x]=1;
             c[y]=1;
             cr++;
             cc++;
          }
          else if(r[x]==0)
          {
             long long int temp = tot0-n;
             temp+=cc;
             cr++;
             tot0=temp;
             r[x]=1;
          }
          else  if(c[y]==0)
          {
             long long int temp = tot0-n;
             temp+=cr;
             cc++;
             tot0=temp;
             c[y]=1;
          }
          tot0=max(1ll*0,tot0);
          ans.push_back(tot0);
      }
      return ans;
      
  }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<vector<int>> arr(k,vector<int>(2));
        for(int i=0;i<k;i++){
            int x, y;
            cin>>x>>y;
            arr[i][0] = x;
            arr[i][1] = y;
        }
        Solution ob;
        vector<long long int> ans = ob.countZero(n,k,arr);
        
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;    
    }
    
    return 0;
}


// } Driver Code Ends