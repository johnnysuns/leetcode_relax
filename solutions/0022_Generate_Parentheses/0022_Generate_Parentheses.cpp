//
// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
//
//
//
// For example, given n = 3, a solution set is:
//
//
// [
//   "((()))",
//   "(()())",
//   "(())()",
//   "()(())",
//   "()()()"
// ]
//


class Solution {
public:
    void generateParenthesis(vector<string> &res, string s, int left,int right,int n){
        if(s.length()==n*2){
            res.push_back(s);
            return;
        }
        if(left<n) generateParenthesis(res,s+"(",left+1,right,n);
        if(right<left)generateParenthesis(res,s+")",left,right+1,n);
    }
    
    vector<string> generateParenthesis(int n) {
        if(n==0)return {""};
        vector<string> res;
        string s="(";
        int left=1;
        int right=0;
        generateParenthesis(res,s,left,right,n);
        return res;
    }
};
