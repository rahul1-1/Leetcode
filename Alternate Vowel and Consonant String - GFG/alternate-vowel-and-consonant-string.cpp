//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
     string rearrange (string S, int N)
    {
        vector<int> vow(26,0) , cons(26);
        int c1=0,c2=0;
        for(auto &it : S)
        {
            if(it=='a' || it=='i' || it=='e' || it=='o' || it=='u') vow[it-'a']++;
            else 
            {
                c2++;
                cons[it-'a']++;
                continue;
            }
            c1++;
        }
        if(abs(c1-c2)>1) return "-1";
       int i=0;
        int l=0,r=0;
        bool f=true;
        while(l<26 && vow[l]==0) l++;
        while(r<26 && cons[r]==0) r++;
        if(c1>c2) 
        {
            S[i++]= (char)('a'+l);
            vow[l]--;
            f=false;
        }
        else if(c2>c1)
        {
              S[i++] = (char)('a'+r);
            cons[r]--;
        }
        while(l<26&& r<26)
        {
         while( l<26 && vow[l]==0) l++;
         while(r<26 && cons[r]==0) r++;
          if(f) 
          {
              S[i++]= (char)('a'+l);
            vow[l]--;
          }
          else 
          {
              S[i++]= (char)('a'+r);
            cons[r]--;
          }
          f= !f;
        }
        return S;
        
    }
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		string s; cin >> s;
		Solution ob;
		cout << ob.rearrange (s, n) << endl;
	}
}
// Contributed By: Pranay Bansal

// } Driver Code Ends