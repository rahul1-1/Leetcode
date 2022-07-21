/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode*root, int l, int r) {
        if(root==NULL || root->next==NULL || l==r)
            return root;
        ListNode* d=new ListNode(0);
        d->next=root;
        
        ListNode*pre=d;
        ListNode*curr=d;
        int t=l;
        while(t-- >0)
        {
            pre=curr;
            curr=curr->next;
        }
        ListNode*nxt=curr->next;

        for(int i=1;i<=r-l;i++)
        {
            curr->next=nxt->next;
            nxt->next=pre->next;
            pre->next=nxt;
            nxt=curr->next;
        }
        return d->next;
        
    }
};