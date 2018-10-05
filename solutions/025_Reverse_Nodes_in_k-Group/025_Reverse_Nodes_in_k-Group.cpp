// Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
//
// k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
//
//
//
//
// Example:
//
// Given this linked list: 1->2->3->4->5
//
// For k = 2, you should return: 2->1->4->3->5
//
// For k = 3, you should return: 3->2->1->4->5
//
// Note:
//
//
// 	Only constant extra memory is allowed.
// 	You may not alter the values in the list's nodes, only nodes itself may be changed.
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
    void reverseGroup(ListNode* p, ListNode* q) {
        ListNode* tmp;
        ListNode* pre = q;
        while(p!=q){
            tmp=p->next;
            p->next=pre;
            pre=p;
            p=tmp;
        }
        q->next=pre;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1)return head;
        ListNode *p=head, *q=p,*next_p,*last_end;
        int i=1;
        //to find head
        while(q){
            //cout<<k<<" 0p:"<<p->val<<"q:"<<q->val<<endl;
            if(++i>k){
                next_p=q->next;
                head=q;
                reverseGroup(p,q);
                last_end=p;
                p->next=next_p;
                p=next_p;
                q=p;
                break;
            }
            q=q->next;
        }
        i=1;
        //rolling!
        while(q){
            //cout<<k<<" 1p:"<<p->val<<"q:"<<q->val<<endl;
            if(++i>k){
                i=2;
                next_p=q->next;
                reverseGroup(p,q);
                last_end->next=q;
                last_end=p;
                p->next=next_p;
                if(next_p==0) break;
                p=next_p;
                q=p;
            }
                
            q=q->next;
        }
        return head;
    }
};
