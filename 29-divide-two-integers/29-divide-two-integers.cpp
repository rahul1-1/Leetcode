class Solution {
public:
    int divide(int di, int dv) {
        if(di==INT_MIN && dv==-1)
            return INT_MAX;
        if(dv==1)
        {
            return di;
        }
       long d=abs(di);
      long div=abs(dv);
        int sig=1;
        if(di<0)
        {
            sig*=-1;
        }
        if(dv<0){
            sig*=-1;
        }
        long ans=0;
        while(d>=div)
        {
            int cnt=0;
            while(d>=(div<<(cnt+1)))
            {
                cnt++;
            }
            ans+=(1<<cnt);
            d=d-(div<<cnt);
        }
        
        return sig*ans;
    }
};