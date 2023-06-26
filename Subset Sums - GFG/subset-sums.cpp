//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    void solve(int ind,int sum,vector<int>&num,int n,vector<int>&res){
    	if(ind==n){
    		res.push_back(sum);
    		return ;
    	}
    	// nonPick 
    	solve(ind+1,sum,num,n,res);
    	//Pick
    	solve(ind+1,sum+num[ind],num,n,res);
    	return;
    }
    vector<int> subsetSums(vector<int> num, int N)
    {
        // Write Your Code here
        vector<int>res;
	int n=num.size();
	solve(0,0,num,n,res);
	return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends