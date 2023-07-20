//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    int findLastOccurence(string A,string B){
        //Code Here
        string s = B +'#' + A;
        int n = s.length();
        int res=-1;
        vector<int>z(n);
        int l=0;
        int r=0;
        for(int i=0;i<n;i++){
            if(i<=r){
                
                z[i] = min(r-i+1,z[i-l]);
            }
            while(i+z[i]<n && s[z[i]]==s[z[i]+i]){
                z[i]++;
            }
            if(i+z[i]-1 > r){
                l = i;
                r=i+z[i]-1;
            }
            if(z[i]==B.length())
            res =  i-B.length();
        }
        
        return res;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string A,B;
        cin>>A>>B;
        Solution ob;
        cout<<ob.findLastOccurence(A,B)<<"\n";
        
    } 
    return 0; 
}
// } Driver Code Ends