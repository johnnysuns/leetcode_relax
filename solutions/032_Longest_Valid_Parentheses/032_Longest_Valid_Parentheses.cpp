// Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
//
// Example 1:
//
//
// Input: "(()"
// Output: 2
// Explanation: The longest valid parentheses substring is "()"
//
//
// Example 2:
//
//
// Input: ")()())"
// Output: 4
// Explanation: The longest valid parentheses substring is "()()"
//
//


class Solution {
public:
    int longestValidParentheses(string s) {
        int top=0;
        int max_len=0;
        int tmp_len;
        int stack[s.length()+1];
        stack[0]=-1;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(') stack[++top]=i;
            else if(top>0){
                tmp_len=i-stack[--top];
                if(tmp_len>max_len) max_len=tmp_len;
            }else stack[0]=i;
            //cout<< s.substr(0,i+1)<<" stack[top]:"<<stack[top]<<" top:"<<top<<" max_len"<<max_len<<endl;
        }
        return max_len;
    }
};
