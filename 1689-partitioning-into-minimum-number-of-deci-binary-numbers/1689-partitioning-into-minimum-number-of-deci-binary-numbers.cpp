class Solution {
public:
    int minPartitions(string n) {
        int mxDigit=0;
        for(auto &x:n)
        {
            mxDigit=max(mxDigit,x-'0');
        }
        return mxDigit;
    }
};