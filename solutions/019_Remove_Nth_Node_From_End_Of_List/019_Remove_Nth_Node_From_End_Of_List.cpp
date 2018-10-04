// Given a linked list, remove the n-th node from the end of list and return its head.
//
// Example:
//
//
// Given linked list: 1->2->3->4->5, and n = 2.
//
// After removing the second node from the end, the linked list becomes 1->2->3->5.
//
//
// Note:
//
// Given n will always be valid.
//
// Follow up:
//
// Could you do this in one pass?
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* rear=head;
        ListNode new_head(0);
        ListNode* precutpoint=&new_head;
        new_head.next=head;
        for(int i=0;i<n;i++)
        {
            rear=rear->next;
        }
        while(rear){
            precutpoint=precutpoint->next;
            rear=rear->next;
        }
        //cut the cutpoint next node
        rear=precutpoint->next;
        precutpoint->next=rear->next;
        delete(rear);
        return new_head.next;
    }
};
