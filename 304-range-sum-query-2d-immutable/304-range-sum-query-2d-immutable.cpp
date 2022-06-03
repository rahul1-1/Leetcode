class NumMatrix {
public:
   vector<vector<int>>pf;
    NumMatrix(vector<vector<int>>&arr) {
       int n=arr.size();
        int m =arr[0].size();
        pf.resize(n+1,vector<int>(m+1));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                pf[i][j]=arr[i-1][j-1]+pf[i-1][j]+pf[i][j-1]-pf[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum=0;
        sum =pf[row2+1][col2+1]-pf[row1-1+1][col2+1]-pf[row2+1][col1-1+1]+pf[row1-1+1][col1-1+1];
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */