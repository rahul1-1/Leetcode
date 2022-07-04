class Solution {
public:
    int candy(vector<int>& ratings) {
        int totcnt=0;
        int f=1;
        int n=ratings.size();
        vector<int>candy(n,1);
      
            for(int i=n-2;i>=0;i--)
            {
                if(ratings[i]>ratings[i+1])
                {
                    candy[i]=candy[i+1]+1;
                  
                }
                
            }
        for(int i=1;i<n;i++)
        {
                if(i!=0&&ratings[i]>ratings[i-1])
                {
                    candy[i]=max(candy[i],candy[i-1]+1);
                   
                }
        }
            
        
        for(auto &x:candy)
        {
            totcnt+=x;
        }
        return totcnt;
    }
};