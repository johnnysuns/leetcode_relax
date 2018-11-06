//
// Given a linked list, determine if it has a cycle in it.
//
//
//
// Follow up:
// Can you solve it without using extra space?
//


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
    bool hasCycle(ListNode *head) {
        ListNode* p0=head;
        if(p0 == NULL) return false;
        ListNode* p1=head->next;
        if(p1 == NULL) return false;
        while((p1!=NULL)&&(p1->next!=NULL)){
            if(p1==p0) return true;
            p1=p1->next->next;
            p0=p0->next;
        }
        return false;
    }
};
