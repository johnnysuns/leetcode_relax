// Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
//
// To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.
//
// Note: Do not modify the linked list.
//
//  
//
// Example 1:
//
//
// Input: head = [3,2,0,-4], pos = 1
// Output: tail connects to node index 1
// Explanation: There is a cycle in the linked list, where tail connects to the second node.
//
//
//
//
// Example 2:
//
//
// Input: head = [1,2], pos = 0
// Output: tail connects to node index 0
// Explanation: There is a cycle in the linked list, where tail connects to the first node.
//
//
//
//
// Example 3:
//
//
// Input: head = [1], pos = -1
// Output: no cycle
// Explanation: There is no cycle in the linked list.
//
//
//
//
//  
//
// Follow-up:
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
    //brute force: to remember all address
    // ListNode *detectCycle(ListNode *head) {
    //     unordered_map<void*,int> addr;
    //     while (head!=NULL){
    //         if(addr[(void*)head]==0)
    //             addr[(void*)head]=1;
    //         else return head; 
    //         head=head->next;
    //     }
    //     return NULL;
    // }
    //memery saving way:two pointers,one goes faster,one goes slower
    ListNode *detectCycle(ListNode *head) {
        ListNode *p=head;
        ListNode *q=p;
        if(q==NULL) return NULL;
        while(q!=NULL){
            p=p->next;
            q=q->next;
            if(q!=NULL) q=q->next;
            else return NULL;
            if(p==q)break;
        }
        if(p==q){
            p=head;
            while(p!=q){
                p=p->next;
                q=q->next;
            }
            return q;
        }
        else{
            return NULL;
        } 
        return NULL;
    }
};
