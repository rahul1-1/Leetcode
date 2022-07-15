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
    int diameterOfBinaryTreeUtil(TreeNode* root,int &maxDiameter)
    {
        if(root==NULL)
            return 0;
        
        int leftDiameter = diameterOfBinaryTreeUtil(root->left,maxDiameter);
        int rightDiameter = diameterOfBinaryTreeUtil(root->right,maxDiameter);
        
        int currDiameter = leftDiameter + rightDiameter + 1;
        maxDiameter = max(maxDiameter, currDiameter) ;
        
        return max(leftDiameter+1, rightDiameter+1);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDiameter=0;
        diameterOfBinaryTreeUtil(root,maxDiameter);
        return maxDiameter-1;
    }
};