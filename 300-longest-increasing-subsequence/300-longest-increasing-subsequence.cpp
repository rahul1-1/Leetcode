class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int sz=nums.size();
        vector<int>dp(sz);
        dp[0]=nums[0];
        int len=1;
        for(int i=1;i<sz;i++)
        {
            if(dp[len-1]<nums[i])
            {
                dp[len++]=nums[i];
            }else{
                auto ind=lower_bound(dp.begin(),dp.begin()+len,nums[i])-dp.begin();
              
                dp[ind]=nums[i];
            }
        }
        return len;
    }
};