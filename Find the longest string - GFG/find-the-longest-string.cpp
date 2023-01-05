//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    string longestString(vector<string> &words)
    {
        // code here
        sort(words.begin(),words.end());
  
        unordered_set<string>st;
        string ans="";
        
        for(auto &s:words)
        {
            st.insert(s);
            bool f=1;
            for(int j=0;j<s.length()-1;j++)
            {
                string temp=s.substr(0,j+1);
                if(st.find(temp)==st.end())
                {
                    f=0;
                    break;
                }
            }
            if(f==1)
            {
                if(s.length()>ans.length())
                {
                    ans=s;
                }
            }
            
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution obj;
        string w = obj.longestString(v);
        cout << w << "\n";
    }
    return 0;
}

// } Driver Code Ends