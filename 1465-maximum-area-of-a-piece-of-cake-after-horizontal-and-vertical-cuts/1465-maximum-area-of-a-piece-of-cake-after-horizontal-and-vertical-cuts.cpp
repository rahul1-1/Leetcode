class Solution {
public:
    int mod=1e9+7;
    int maxArea(int H, int W, vector<int>& h, vector<int>& v) {
        h.push_back(H);
        v.push_back(W);
         
        sort(h.begin(),h.end());
        sort(v.begin(),v.end());
        long hm=h[0],vm=v[0];
        for(int i=1;i<h.size();i++)
        {
            if(h[i]-h[i-1]>hm)
            {
                hm=h[i]-h[i-1];
            }
        }
        for(int i=1;i<v.size();i++)
        {
            if(v[i]-v[i-1]>vm)
            {
                vm=v[i]-v[i-1];
            }
        }
        return (vm % (1000000000 + 7) * hm % (1000000000 + 7)) % (1000000000 + 7);
    }
};