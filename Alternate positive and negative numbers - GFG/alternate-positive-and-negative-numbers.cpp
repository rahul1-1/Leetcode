//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	void rearrange(int arr[], int n) {
	    // code here
	    int temp[n];
	    int i=0,j=n-1;
	    for(int k=0;k<n;k++)
	    {
	        if(arr[k]>=0)
	        {
	            temp[i++]=arr[k];
	        }else{
	            temp[j--]=arr[k];
	        }
	    }
	    i=0,j=n-1;
	    for(int k=0;k<n;k++)
	    {
	        if(k%2==0)
	        {
	            if(temp[i]<0)
	            {
	                arr[k]=temp[j--];
	            }
	            else{
	            arr[k]=temp[i++];
	            }
	        }
	        else{
	            if(temp[j]>=0)
	            {
	                arr[k]=temp[i++];
	            }
	            else{
	            arr[k]=temp[j--];
	            }
	        }
	    }
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends