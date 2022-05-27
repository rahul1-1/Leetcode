class Solution {
       bool check(int x,int y,char ch,vector<vector<char>>& board)
    {
           int cnt=0;
        for(int i=0;i<9;i++)
        {
           //cout<<"  "<<board[i][y]<<" ";
            if(board[x][i] == ch)
                cnt++;
            if(board[i][y] == ch)
                cnt++;
            if(board[3*(x / 3) + i/3][3*(y/3)+i%3] == ch)
                cnt++;
        }
        if(cnt>3)
            return false;
           return true;
    }
     bool solve(vector<vector<char>>& board)
    {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]!='.')
                {
                    
                   
                        if(!check(i,j,board[i][j],board))
                        {
                            return false;
                        }
                    
                }
            }
        }
        return true;
    }
public:
    
    bool isValidSudoku(vector<vector<char>>& board) {
        return  solve(board);
    }
};