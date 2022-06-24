class Solution {
public:
    bool isPossible(vector<int>& target) {
        if(target.size()==1&&target[0]==1)
            return true;
        if(target.size()==1 &&target[0]>1)
            return false;
        priority_queue<long long int> pq;
        long long int sum=0;
        bool flag=true;
        for(int i=0;i<target.size();i++)
        {
            pq.push(target[i]);
            sum+=target[i];
        }
        while(pq.top()!=1)
        {
            long long int num = pq.top();
            pq.pop();
            long long int new_sum = sum - num; 
            num =num-(sum-num);
            
            if(num<1)
            {
                flag = false;
                break;
            }
            num=num%(sum-num);
            if(num==0)
            {
                flag = false;
                break;
            }
            pq.push(num);
            sum = new_sum + num;
        }
        return flag;
    }
};