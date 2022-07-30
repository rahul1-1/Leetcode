class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
      vector<string>ans;
        vector<int>v1(26,0);
        for(int i=0;i<B.size();i++)
        {
            vector<int>v2(26,0);
            for(int j=0;j<B[i].size();j++)
                v2[B[i][j]-'a']++;
            for(int j=0;j<26;j++)
                v1[j]=max(v1[j],v2[j]);
        }
        for(int i=0;i<A.size();i++)
        {
            vector<int>arr1(26,0);
            for(int j=0;j<A[i].size();j++)
                arr1[A[i][j]-'a']++;
            bool flag=true;
            for(int j=0;j<26;j++)
            {
                if(v1[j]-arr1[j]>0)
                {
                    flag=false;
                    break;
                }
            }
            if(flag) ans.push_back(A[i]);
        }
        return ans;
    }
};