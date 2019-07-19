# 24. Swap Nodes in Pairs

## 简析

    单向链表，每两个节点交换。要求只能改变链接关系，不能更改节点值，需求空间为常量大小。

## 方法一：中间变量

最容易想到的方法就是使用两个指针p,q指向每次交换的前后两个数。首先，确定p->next和q->next,然后后移p,q，过程中需要存一下下次的p位置，因为赋值next后有可能丢失对q->next的指针。

考虑一下以下几种情况：
1. 空链表
2. 只有一个节点
3. 节点数为奇数
4. 节点数为偶数

**我的代码：**
```cpp
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL) return NULL;
        ListNode *p=head,*tmp;
        ListNode *q=head->next;
        head=(q)?(q):(p);
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
```


## 方法二：多重指针

讨论区中看到了一种奇技淫巧，利用双重指针pp代替了作为中间变量的tmp，相当优雅。

看图说话

1. 初始状态，pp=&head
   
2. a = *pp，b = a->next

||Node0| ||Node1| ||Node2| ||Node3||
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
|Pointer|head ⬇|⬅pp| 
|ListNode|\|1|to 2\|| |\|2|to 3\|| |\|3|to 4\|| |\|4|to null\|| 
|Pointer|a⬆| ||b⬆|

3. 更新next
   
||Node0| ||Node1| ||Node2| ||Node3||
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
|Pointer|head ⬇|⬅pp| 
|ListNode|\|1|**to 3**\|| |\|2|**to 1**\|| |\|3|to 4\|| |\|4|to null\|| 
|Pointer|a⬆| ||b⬆|

4. 更新*pp，***pp = b**， head指向了（Node1）
   
||Node0| ||Node1| ||Node2| ||Node3||
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
|Pointer|||| **head ⬇**|⬅pp
|ListNode|\|1|to 3\|| |\|2|to 1\|| |\|3|to 4\|| |\|4|to null\|| 
|Pointer|a⬆| ||b⬆|

5. 更新pp，pp指向a->next
   
||Node0| ||Node1| ||Node2| ||Node3||
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
|Pointer|||| head ⬇|
|ListNode|\|1|to 3\|| |\|2|to 1\|| |\|3|to 4\|| |\|4|to null\|| 
|Pointer|a⬆|**pp⬆** ||b⬆|

6. 到2，继续迭代

```cpp
ListNode* swapPairs(ListNode* head) {
    ListNode **pp = &head, *a, *b;
    while ((a = *pp) && (b = a->next)) {
        a->next = b->next;
        b->next = a;
        *pp = b;
        pp = &(a->next);
    }
    return head;
}
```
