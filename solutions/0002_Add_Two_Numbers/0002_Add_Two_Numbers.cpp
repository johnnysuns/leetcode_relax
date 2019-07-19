// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
//
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.
//
// Example:
//
//
// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8
// Explanation: 342 + 465 = 807.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int digit=l1->val+l2->val;
        int res=0;
        if (digit>9)
        {
            digit-=10;
            res ++;
        }
        ListNode* head=new ListNode(digit);

        ListNode* newnode=new ListNode(res);
        ListNode* pl1=l1;
        ListNode* pl2=l2;
        head->next =newnode;
        newnode=head;
        while((pl1->next)&&(pl2->next))
        {
            newnode=newnode->next;
            newnode->val+=(pl1->next->val+pl2->next->val);
            pl1=pl1->next;
            pl2=pl2->next;
            res=0;
            if (newnode->val>9)
            {
                newnode->val-=10;
                res ++;
            }
            newnode->next= new ListNode(res);
        }
        if(pl2->next)
        {
            pl1=pl2;
        }
        if(pl1->next)
        {
            if(newnode->next->val!=0)
            {
                delete newnode->next;
                newnode->next=pl1->next;
                (pl1->next->val)++;
                while(pl1->next->val>9)
                {
                    pl1->next->val-=10;
                    pl1=pl1->next;
                    if(pl1->next==NULL)
                    {
                        pl1->next = new ListNode(1);
                    }
                    else
                    {
                        pl1->next->val++;
                    }
                }
            }
            else
            {
                delete newnode->next;
                newnode->next=pl1->next;
            }
        } else
        {
            if(newnode->next->val==0 && newnode->next->next==NULL) {
                delete newnode->next;
                newnode->next = NULL;
            }
            if(head->next)
            {
                if((head->next->next==NULL)&&(head->next->val==0))
                {
                    delete head->next;
                    head->next=NULL;
                }
            }
        }
        return head;
    }
};
