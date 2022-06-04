class Solution {
public:
  
    bool isSafe(int n,int r,int c ,vector<vector<string>>&ans,vector<string>&ds)
    {
        //row
        int tot=0;
        for(int i=0;i<n;i++)
        {
            if(ds[r][i]=='Q')
                tot++;
        }
       if(tot>0)
           return false;
        tot=0;
       //colum
        for(int i=0;i<n;i++)
        {
            if(ds[i][c]=='Q')
              tot++;
        }
        
     if(tot>0)
         return false;
        tot=0;
         for(int i=0;i<n;i++)
        {
            if(r+i<n&&c+i<n)
                {
                if(ds[r+i][c+i]=='Q')
                    tot++;
                }
             else
                 break;
        }
        
        if(tot>0)
         return false;
        tot=0;
        
        
          for(int i=0;i<n;i++)
        {
            if(r-i>=0&&c-i>=0)
              {
                if(ds[r-i][c-i]=='Q')
                   tot++;
            }
              else
                  break;
        }
        if(tot>0)
         return false;
        tot=0;
           for(int i=0;i<n;i++)
        {
            if(r+i<n&&c-i>=0)
               {
                if(ds[r+i][c-i]=='Q')
                    tot++;
            }
               else 
                   break;
        } 
         if(tot>0)
         return false;
        tot=0;
        
        for(int i=0;i<n;i++)
        {
            if(r-i>=0&&c+i<n)
                {
                    if(ds[r-i][c+i]=='Q')
                    tot++;
                }
        }
        if(tot>0)
         return false;
        return true;
    }
  void  solve(int n,int r,vector<vector<string>>&ans,vector<string>&ds, vector<int>&c, vector<int>&d, vector<int>&rd)
    {
        if(r==n)
        {
            ans.push_back(ds);
           return ;
            
        }
        for(int i=0;i<n;i++)
        {
           // if(isSafe(n,r,i,ans,ds)==true)
            if(c[i]==0&&d[r+i]==0&&rd[n+ r-i-1]==0)
            {
                ds[r][i] = 'Q' ;
                c[i]=1;
                d[r+i]=1;
                rd[n+r-i-1]=1;
                solve(n,r+1,ans,ds,c,d,rd);
                ds[r][i]='.';
                c[i]=0;
                d[r+i]=0;
                rd[n+r-i-1]=0;
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        string s="";
          vector<string>ds;
        vector<int>c(n,0);
        vector<int>d(2*n-1 ,0);
        vector<int>rd(2*n-1,0);
    vector<vector<string>>ans;
        for(int i=0;i<n;i++)
            s+=".";
        ds=vector<string>(n,s);
        solve(n,0,ans,ds,c,d,rd);
        return ans;
    }
};