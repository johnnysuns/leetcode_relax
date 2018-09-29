#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

  //Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
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
            if(head->next) {
                if ((head->next->next == NULL) && (head->next->val == 0)) {
                    delete head->next;
                    head->next = NULL;
                }
            }
        }
        return head;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

string listNodeToString(ListNode* node) {
    if (node == nullptr) {
        return "[]";
    }

    string result;
    while (node) {
        result += to_string(node->val) + ", ";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode* l1 = stringToListNode(line);
        getline(cin, line);
        ListNode* l2 = stringToListNode(line);

        ListNode* ret = Solution().addTwoNumbers(l1, l2);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}