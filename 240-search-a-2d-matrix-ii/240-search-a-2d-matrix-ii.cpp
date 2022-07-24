class Solution {
public:
    bool searchMatrix(vector<vector<int>>&arr, int k) {
        int n = arr.size();
        int m=arr[0].size();
        int i=0;
        int j=m-1;
        while(i>=0&&j>=0&&i<n&&j<m)
        {
            if(arr[i][j]>k)
                j--;
            else if(arr[i][j]<k)
                i++;
            else
                return true;
        }
        return false;
    }
};