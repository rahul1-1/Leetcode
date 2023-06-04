//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseEqn (string s)
        {
            //code here.
            string ans="";
            string curr="";
            for(int i=s.length()-1;i>=0;i--)
            {
                if(s[i]=='+'||s[i]=='-' || s[i] == '*' || s[i] == '/')
                {
                    reverse(curr.begin(),curr.end());
                    ans+=curr;
                    ans+=s[i];
                    curr="";
                }
                else{
                    curr+=s[i];
                }
            }
            reverse(curr.begin(),curr.end());
            ans+=curr;
            return ans;
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends