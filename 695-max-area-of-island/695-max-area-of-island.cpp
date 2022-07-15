class Solution {
    void solve(int i,int j,int n,int m,vector<vector<int>>& grid,int &t)
    {
        if(i<0 || j<0 ||i>=n||j>=m|| grid[i][j]<=0)
            return ;
        t++;
        grid[i][j]-=2;
        solve(i+1,j,n,m,grid,t);
        solve(i-1,j,n,m,grid,t);
        solve(i,j+1,n,m,grid,t);
        solve(i,j-1,n,m,grid,t);
        
        
        
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        int mx=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    int cur=0;
                    solve(i,j,n,m,grid,cur);
                    mx=max(mx,cur);
                    
                }
            }
        }
        return mx;
    }
};