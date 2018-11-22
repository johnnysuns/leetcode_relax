// Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
//
// If the last word does not exist, return 0.
//
// Note: A word is defined as a character sequence consists of non-space characters only.
//
// Example:
//
// Input: "Hello World"
// Output: 5
//
//


class Solution {
public:
    int lengthOfLastWord(string s) {
        int end=s.length()-1;
        int i;
        while(end>=0&&s[end]==' ') end--;
        for(i=end;i>=0;i--){
            if(s[i]==' '){
                return end-i;
            }
        }
        if(i!=end)return end+1;
        return 0;
    }
};
