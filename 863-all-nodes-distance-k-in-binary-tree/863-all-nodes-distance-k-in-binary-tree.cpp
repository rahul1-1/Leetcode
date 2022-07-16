/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, TreeNode* par, unordered_map<TreeNode*,TreeNode*>&parArr)
    {
         if(root==NULL)
            return ;
        
        parArr[root]=par;
        solve(root->left,root,parArr);
        solve(root->right,root,parArr);
        
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(root==NULL)
            return {};
        unordered_map<TreeNode*,TreeNode*>par;
        unordered_map<TreeNode*,bool>vis;
        vector<int>res;
        solve(root,NULL,par);
        queue<TreeNode*>q;
        q.push(target);
        vis[target]=true;
        while(!q.empty())
        {
           
            int sz=q.size();
          //  cout<<endl<<" sz "<<sz<<"  k "<<k<<endl;
            while(sz--)
            {
                TreeNode *temp=q.front();
               // cout<<" node => "<<temp->val<<"  ";
                q.pop();
                if(k==0)
                {
                    res.push_back(temp->val);
                }
                if(temp->left!=NULL && vis.find(temp->left)==vis.end())
                {
                    vis[temp->left]=true;
                    q.push(temp->left);
                }
                if(temp->right && vis.find(temp->right)==vis.end())
                {
                    vis[temp->right]=true;
                    q.push(temp->right);
                }
                if(par[temp]&&vis.find(par[temp])==vis.end())
                {
                  //  cout<<" par node "<<par[temp]->val<<"  ";
                    vis[par[temp]]=true;
                    q.push(par[temp]);
                }
            }
             k--;
            if(k<0)
                break;
            
            
        }
       
        return res;
        
    }
};