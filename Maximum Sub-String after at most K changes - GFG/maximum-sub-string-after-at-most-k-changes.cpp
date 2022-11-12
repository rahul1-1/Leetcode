//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int characterReplacement(string s, int k){
		    // Code here
		    int j=0;
		    int n=s.length();
		    if(n==1||k==n)
		    return n;
		    int curr=0;
		    int mx=0;
		    vector<vector<int>>dp(n,vector<int>(26,0));
		      for(int i=0;i<n;i++)
		    {

		            dp[i][s[i]-'A']=1;
		        
		    }
	
		    for(int i=1;i<n;i++)
		    {
		        int cm=0;
		        for(int j=0;j<26;j++)
		        cm=max(cm,dp[i][j]+dp[i-1][j]);
		        
		        if(cm+k >=(i-j+1))
		        {
		            mx=(i-j+1);
		        }else{
		            dp[i][s[j]-'A']--;
		            j++;
		        }
		        if(i>0)
		        {
	      for(int j=0;j<26;j++)
	        {
	            dp[i][j]+=dp[i-1][j];
	        }
		        }
		    }
		    if(mx==0)
		    return 1;
		    
		    return mx;
		    
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		int k;
		cin >> k;
		Solution obj;
		int ans = obj.characterReplacement(s, k);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends