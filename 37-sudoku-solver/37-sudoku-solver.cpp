class Solution {
public:
    bool check(int x,int y,char ch,vector<vector<char>>& board)
    {
        for(int i=0;i<9;i++)
        {
           //cout<<"  "<<board[i][y]<<" ";
            if(board[x][i] == ch)
                return false;
            if(board[i][y] == ch)
                return false;
            if(board[3*(x / 3) + i/3][3*(y/3)+i%3] == ch)
                return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board)
    {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]=='.')
                {
                    for(char ch='1';ch<='9';ch++)
                    {
                        
                        if(check(i,j,ch,board))
                        {
                            board[i][j]=ch;
                        
                        if(solve(board)==true)
                            return true;
                        else
                            board[i][j]='.'; 
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        
        solve(board);
    }
};