// Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
//
// Example 1:
//
//
// Input: "babad"
// Output: "bab"
// Note: "aba" is also a valid answer.
//
//
// Example 2:
//
//
// Input: "cbbd"
// Output: "bb"
//
//


class Solution {
private:

public:
    string longestPalindrome(string s) {
        int i=0;
        int max_len=0;
        int max_start=0;
        int cur_len=0;
        int left,right;
        int a=s.length();
        while(i<a) {
            left=i,right=i;
            while(left>=0 && right<=a && s[left]==s[right]){
                left--;
                right++;
            }

            cur_len=right-left-1;
            if(cur_len>max_len){
                max_len=cur_len;
                max_start=left+1;
            }
            cur_len=0;
            left=i,right=i+1;
            while(left>=0 && right<=a && s[left]==s[right]){
                left--;
                right++;
            }
            cur_len=right-left-1;
            if(cur_len>max_len){
                max_len=cur_len;
                max_start=left+1;
            }
            cur_len=0;

            i++;
        }

        return s.substr(max_start,max_len);
    }
};
