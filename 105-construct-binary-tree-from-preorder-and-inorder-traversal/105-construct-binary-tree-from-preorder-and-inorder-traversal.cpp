/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int st=0;
    unordered_map<int,int>mp;
 
    TreeNode* solve(vector<int>&p,vector<int>&i,int s,int e)
    {
        if(s>e)
            return NULL;
        TreeNode *root=new TreeNode(p[st++]);
        int mid=mp[p[st-1]];
        root->left=solve(p,i,s,mid-1);
        root->right=solve(p,i,mid+1,e);
        return root;
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        for(int i=0;i<in.size();i++)
        {
            mp[in[i]]=i;
        }
        return solve(pre,in,0,in.size()-1);
    }
};