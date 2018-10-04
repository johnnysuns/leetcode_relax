// Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
//
// Example:
//
// Input: 1->2->4, 1->3->4
// Output: 1->1->2->3->4->4
//
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head;
        ListNode* p;
        if(l1==NULL) {
            if (l2 == NULL) {
                return NULL;
            } else
            {
                return l2;
            }
        } else if(l2 == NULL)
        {
            return l1;
        }
        
        if(l1->val>l2->val) {
            head=l2;
            l2=l2->next;
        } else {
            head=l1;
            l1=l1->next;
        }
        p=head;
        while((l1!=NULL)&&(l2!=NULL))
        {
            if(l1->val>l2->val) {
                p->next=l2;
                p=p->next;
                //if(l2->next)
                    l2=l2->next;
            } else {
                p->next=l1;
                p=p->next;
                //if(l1->next)
                    l1=l1->next;
            }
        }

        if(l2)
        {
            p->next=l2;
        }else
        if(l1)
        {
            p->next=l1;
        }
        return head;
    }
};
