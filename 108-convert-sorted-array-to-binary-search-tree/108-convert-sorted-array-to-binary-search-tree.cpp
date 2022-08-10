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
    TreeNode* solve(vector<int>&arr,int l,int r)
        
    {

        if(l>r)
            return NULL;
    
        int mid=(l+r)/2;
                TreeNode* root=new TreeNode(arr[mid]);
        root->left=solve(arr,l,mid-1);
        root->right=solve(arr,mid+1,r);
    return root;
       
       
    }
    TreeNode* sortedArrayToBST(vector<int>&arr) {
        int n=arr.size();
        if(n==0)
            return NULL;
        return solve(arr,0,n-1);
    }
};