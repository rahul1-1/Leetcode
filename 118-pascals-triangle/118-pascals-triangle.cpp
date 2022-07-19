class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>>res;
        res.push_back({1});
        for(int i=2;i<=numRows;i++)
        {
            vector<int>curr(i);
            curr[0]=1;
           for(int j=1;j<i-1;j++)
           {

             curr[j]=res[i-2][j-1]+res[i-2][j];
           }

            curr[i-1]=1;
            res.push_back(curr);
        }
        return res;
    }
};