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
    ListNode* partition(ListNode* root, int x) {
        if(root==NULL)
            return root;
        ListNode* l1=new  ListNode(-1);
        ListNode* l2= new ListNode(-1);
        ListNode* t1=l1;
        ListNode* t2=l2;
        while(root!=NULL)
        {
            if(root->val<x)
                t1->next=root,t1=t1->next;
            else
                t2->next=root,t2=t2->next;   
            root=root->next;
        }
        t2->next=NULL;
        t1->next=l2->next;
        return l1->next;
        
    }
};