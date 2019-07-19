// Given a linked list, rotate the list to the right by k places, where k is non-negative.
//
// Example 1:
//
//
// Input: 1->2->3->4->5->NULL, k = 2
// Output: 4->5->1->2->3->NULL
// Explanation:
// rotate 1 steps to the right: 5->1->2->3->4->NULL
// rotate 2 steps to the right: 4->5->1->2->3->NULL
//
//
// Example 2:
//
//
// Input: 0->1->2->NULL, k = 4
// Output: 2->0->1->NULL
// Explanation:
// rotate 1 steps to the right: 2->0->1->NULL
// rotate 2 steps to the right: 1->2->0->NULL
// rotate 3 steps to the right: 0->1->2->NULL
// rotate 4 steps to the right: 2->0->1->NULL
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
    ListNode* rotateRight(ListNode* head, int k) {
        
        ListNode *rear=head;
        ListNode *new_rear=head;
        if(head==NULL) return NULL;
        int n=1;
        //find rear && count n;
        while(rear->next){
            n++;
            rear=rear->next;
        }
        k%=n;
        k=n-k;
        //cout<<k<<endl;
        //find cut point
        for(int i=1;i<k;i++){
            new_rear=new_rear->next;
        }
        rear->next=head;
        head=new_rear->next;
        new_rear->next=NULL;
        return head;
    }
};
