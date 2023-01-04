//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  int find(int i,vector<vector<int>>&v)
    {
        int lo = i+1, hi = v.size()-1; 
         
        while (lo <= hi) 
        { 
            int mid = (lo + hi) / 2; 
            if (v[mid][0] >= v[i][1]) 
            { 
                if (v[mid - 1][0] >= v[i][1]) 
                    hi = mid - 1; 
                else
                    return mid; 
            } 
            else
                lo = mid + 1; 
        } 
        return -1; 
    }
    int solve(int i,vector<vector<int>>&arr,map<int,int>&mp)
    {
        if(i==arr.size())
            return 0;
        if(mp.find(i)!=mp.end())
            return mp[i];
        int nxt=find(i,arr);
        int inc = arr[i][2]+ (nxt==-1?0:solve(nxt,arr,mp));
        int ex =solve(i+1,arr,mp);
        return mp[i] =max(inc,ex);
        
    }
    int maximum_profit(int n, vector<vector<int>> &arr) {
        // Write your code here.
     map<int,int>dp;
        sort(arr.begin(),arr.end());
        
        return solve(0,arr,dp);
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> intervals(n, vector<int>(3));
        for (int i = 0; i < n; i++) {
            cin >> intervals[i][0] >> intervals[i][1] >> intervals[i][2];
        }
        Solution obj;
        cout << obj.maximum_profit(n, intervals) << endl;
    }
    return 0;
}

// } Driver Code Ends