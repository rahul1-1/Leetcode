class Solution {
public:
    int minDeletions(string s) {
        vector<int>frq(26,0);
        for(auto&x:s)
        {
            frq[x-'a']++;
        }
        sort(frq.begin(),frq.end());
        
        int n=s.length();
        int lstFrq=frq[25];
        int cnt=0;

        for(int i=25;i>=0;i--)
        {
            if(frq[i]==0)
            {
                break;
            }
           
             if(frq[i]>lstFrq)
            {
                cnt+=frq[i]-lstFrq;
                frq[i]= lstFrq;
                
                
            }
             lstFrq=max(0,frq[i]-1);
           
            
        }
        return cnt;
    }
};