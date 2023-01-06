//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
  public:
    int shortestPath(int Num1,int Num2)
    {   
        // Complete this function using prime vector
        int n = 10007;
        bool prime[n];
	    memset(prime, true, sizeof(prime));

	    for (int p = 2; p * p <= n; p++) {
    		if (prime[p] == true) {
    			for (int i = p * p; i <= n; i += p)
    				prime[i] = false;
    		}
    	}
    	queue<int>q;
    	q.push(Num1);
    	int d=0;
    	while(!q.empty())
    	{
    	    int sz=q.size();
    	    while(sz-- > 0)
    	    {
    	        int temp = q.front();
    	        q.pop();
    	        if(temp==Num2)
    	        return d;
    	        for(int i=1;i<=9;i++)
    	        {
    	           // cout<<" temp1 "<<(i*1000)<<" %  "<<(temp%1000);
    	            int temp1 = i*1000 + temp%1000;
    	           // cout<<" temp1 "<<temp1<<endl;
    	            if(temp1!=temp && prime[temp1]==true)
    	            {
    	                q.push(temp1);
    	            }
    	        }
    	        int k = 1000;
    	        for(int i=1;i<=3;i++)
    	        {
    	            for(int j=0;j<=9;j++)
    	            {
    	                int temp1 = ((temp/k)*10 + j);
    	                temp1 = temp1*(k/10) + (temp%(k/10));
    	                if(temp1!=temp && prime[temp1]==true)
            	            {
            	                q.push(temp1);
            	            }
    	            }
    	            k/=10;
    	        }
    	    }
    	    d++;
    	}
    	return -1;
    }
};


//{ Driver Code Starts.
signed main()
{
    int t;
    cin>>t;
    Solution obj;
    while(t--)
    {
        int Num1,Num2;
        cin>>Num1>>Num2;
        int answer=obj.shortestPath(Num1,Num2);
        cout<<answer<<endl;
    }
}
// } Driver Code Ends