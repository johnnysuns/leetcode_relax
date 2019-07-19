// Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.
//
// Example 1:
//
//
// Input: 121
// Output: true
//
//
// Example 2:
//
//
// Input: -121
// Output: false
// Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
//
//
// Example 3:
//
//
// Input: 10
// Output: false
// Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
//
//
// Follow up:
//
// Coud you solve it without converting the integer to a string?
//


class Solution {
public:
    bool isPalindrome(int x) {
        int i=0;
        int x_=0;
        int dig;
        if (x<0||(x!=0&&x%10==0))return false;
        while(x_<x) {
            dig=x%10;
            x/=10;
            x_=x_*10+dig;
        }

        if((x==x_)||(x_/10==x)){
            return true;
        }
        return false;
    }
};
