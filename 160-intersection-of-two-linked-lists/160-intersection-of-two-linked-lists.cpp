/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* l1=headA;
        ListNode* l2=headB;
        while(l1!=l2)
        {
            l1=l1==NULL?headB:l1->next;
            l2=l2==NULL?headA:l2->next;
        }
        return l1;
    }
};