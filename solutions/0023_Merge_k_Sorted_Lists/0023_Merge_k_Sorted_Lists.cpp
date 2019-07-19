// Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
//
// Example:
//
//
// Input:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// Output: 1->1->2->3->4->4->5->6
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        list<ListNode*> cur_head;
        int cur_line_index=0;
        ListNode *min1_node,*min2_node;
        ListNode head=ListNode(INT_MAX);//=lists[0];
        auto it=cur_head.begin();
        auto it_min1=it;
        auto it_min2=it;
        for(int i=0;i<lists.size();i++){
            if(lists[i]!=NULL){
                cur_head.push_back(lists[i]);
                 if(lists[i]->val < head.val){
                     head.val=lists[i]->val;
                     it_min1=cur_head.end();
                     it_min1--;
                }
            }
        }
        min1_node=*(it_min1);
        head.next=min1_node;
        //int count=0;
        int tmp;
        
        while(cur_head.size()>1){
            //count++;
            it=cur_head.begin();
            tmp=INT_MAX;
            //find min2 node
            while (it!=cur_head.end()){
                if(((*it)->val < tmp)&&(it!=it_min1)){
                    min2_node=*it;
                    tmp=min2_node->val;
                    it_min2=it;
                }
                it++;
            }
            //cout<<count<<" it1:"<<(*it_min1)->val<<" it2:"<<(*it_min2)->val<<endl;
            //cut && Stitching
            while((min1_node->next)&&(min1_node->next->val<=min2_node->val)){
                min1_node=min1_node->next;
            }
            
            *it_min1=min1_node->next;
            min1_node->next=min2_node;
            if(*it_min1==NULL) cur_head.erase(it_min1);
            //last min2 is next min1
            it_min1=it_min2;
            min1_node=min2_node;
        }
        return head.next;

    }
};
