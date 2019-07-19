// Given a linked list, swap every two adjacent nodes and return its head.
//
// You may not modify the values in the list's nodes, only nodes itself may be changed.
//
//  
//
// Example:
//
//
// Given 1->2->3->4, you should return the list as 2->1->4->3.
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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL) return NULL;
        ListNode *p=head,*tmp;
        ListNode *q=head->next;
        ListNode *HEAD=(q)?(q):(p);
        while(p && q){
            //cout<<"before: p:"<<p->val<<" q:"<<q->val<<endl;
            tmp=q->next;
            p->next=(tmp)?((tmp->next)?(tmp->next):(tmp)):(NULL);
            q->next=p; 
            p=tmp;
            if(p)q=p->next;
        }
        return HEAD;
    }
};
