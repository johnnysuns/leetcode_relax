// Given a string, find the length of the longest substring without repeating characters.
//
//
// Example 1:
//
//
// Input: "abcabcbb"
// Output: 3 
// Explanation: The answer is "abc", with the length of 3. 
//
//
//
// Example 2:
//
//
// Input: "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
//
//
//
// Example 3:
//
//
// Input: "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3. 
//              Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
//
//
//
//
//


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int check_exist[256]={0};
        int max_length = 0;
        int temp_length=0;
        for(int i=0;i<s.size();i++)
        {
            if(check_exist[s[i]])
            {
                if(temp_length>max_length)
                {
                    max_length=temp_length;
                }
                i=check_exist[s[i]];
                if(s.size()-i<max_length) break;
                memset(check_exist,0,sizeof(check_exist));
                check_exist[s[i]]=i+1;
                temp_length=0;
            } else
            {
                check_exist[s[i]]=i+1;//record last index
            }
            temp_length++;
        }
        if(temp_length>max_length) max_length=temp_length;
        return max_length;
    }
};
