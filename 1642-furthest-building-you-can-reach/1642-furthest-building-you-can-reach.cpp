class Solution {
public:
    int furthestBuilding(vector<int>&arr, int b, int l) {
        priority_queue<int>pq;
        int i=0;
        for(i ;i<arr.size()-1;i++)
        {
            int d=arr[i+1]-arr[i];
            if(d<=0)continue;
            if(d<=b)
            {
                b-=d;
                pq.push(d);
            }
            else if(l>0)
            {
                if(pq.size()>0)
                {
                    int x= pq.top();
                    if(x>d)
                    {
                        b+=x;
                    b-=d;
                    pq.pop();
                    pq.push(d);
                    }
                }
                l--;
            }
            else{
                break;
            }
        }
        return i;
    }
};