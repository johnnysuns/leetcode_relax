# 19. Remove Nth Node From End of List

## 简析

    单向链表删除倒数第n个节点。输出头指针，要特别注意一下**头指针可能被删除**，所以需要新建一个node指向头指针，将这个node作为新头指针，最终输出node->next。

## 方法一：遍历两遍

最容易想到的方法就是遍历一遍获取长度l，计算倒数第n个节点的正序序号。第二遍遍历删除该节点。

## 方法二：遍历一遍

比较巧妙的方法是设定两个指针，第二个先遍历n个，然后两指针同时next，直到第二个指针先到链末，第一个指针自然指向的是倒数n个节点。查找和删除时注意一下链表指针前后关系，可前不可后

## 我的代码：

```cpp
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
```
