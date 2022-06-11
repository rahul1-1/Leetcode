class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        if(sum<x)
        {
            return -1;
        }
        if(sum==x)
        {
            return n;
        }
        int len=INT_MIN;
        int remSum=sum-x;
        int currSum=0;
        int i=0;
                

        for(int j=0;j<n;j++)
        {
            
            currSum+=nums[j];
            
            while(currSum>=remSum)
            {
               
                if(currSum==remSum)
                {
                    
                    len=max(len,j-i+1);
                }
                 currSum-=nums[i++];
            }
        }
                

        return len==INT_MIN?-1:n-len;
    }
};