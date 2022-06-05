class Solution {
public:
    
/**********************************************************
    N Queens - Branch And Bound

https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/nqueens-branch-and-bound-official/ojquestion
***************************************************************/
    
    
    
    void solve(vector<vector<bool>>&b,int n,int row,vector<bool>&c,vector<bool>&rd,vector<bool>&nd,int &cnt)
{
    if(row==b[0].size())
    {
        cnt++;
        return;
    }
   for(int i=0;i<n;i++)
   {
       if(c[i]==false&&nd[row+i]==false&&rd[n+row-i-1]==false)
       {
           b[row][i]=true;
           c[i]=true;
           rd[n+row-i-1]=true;
           nd[row+i]=true;
           solve(b,n,row+1,c,rd,nd,cnt);
            b[row][i]=false;
           c[i]=false;
           rd[n+row-i-1]=false;
           nd[row+i]=false;
       }
   }
}
    int totalNQueens(int n) {
         vector<bool>c(n,false);
    vector<bool>nd(2*n-1,false);
    vector<bool>rd(2*n-1,false);
    vector<vector<bool>> b( n , vector<bool> (n, false));
  
        int cnt=0;
   solve(b,n,0,c,rd,nd,cnt);
   return cnt;
    }
};