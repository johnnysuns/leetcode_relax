// Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*'.
//
//
// '?' Matches any single character.
// '*' Matches any sequence of characters (including the empty sequence).
//
//
// The matching should cover the entire input string (not partial).
//
// Note:
//
//
// 	s could be empty and contains only lowercase letters a-z.
// 	p could be empty and contains only lowercase letters a-z, and characters like ? or *.
//
//
// Example 1:
//
//
// Input:
// s = "aa"
// p = "a"
// Output: false
// Explanation: "a" does not match the entire string "aa".
//
//
// Example 2:
//
//
// Input:
// s = "aa"
// p = "*"
// Output: true
// Explanation: '*' matches any sequence.
//
//
// Example 3:
//
//
// Input:
// s = "cb"
// p = "?a"
// Output: false
// Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
//
//
// Example 4:
//
//
// Input:
// s = "adceb"
// p = "*a*b"
// Output: true
// Explanation: The first '*' matches the empty sequence, while the second '*' matches the substring "dce".
//
//
// Example 5:
//
//
// Input:
// s = "acdcb"
// p = "a*c?b"
// Output: false
//
//


class Solution {
public:
    bool isMatch(string s, string p) {
        int match[s.length()+1][p.length()+1]={0};
        match[0][0]=1;
        for(int i=0;i<p.length();i++){
            match[0][i+1]=match[0][i]&& (p[i]=='*');
        }
        for(int i=0;i<s.length();i++){
            for(int j=0;j<p.length();j++){
                if(p[j]==s[i]){
                    match[i+1][j+1]=match[i][j];
                }else{
                    switch(p[j]){
                        case '?':
                            match[i+1][j+1]=match[i][j];
                            break;
                        case '*':
                            match[i+1][j+1]=match[i][j]//one characters
                                ||match[i+1][j]//empty
                                ||match[i][j+1];//same characters
                            break;
                        default:
                            break;
                    }
                }
            }
        }
        // cout<<endl;
        // for(int i=0;i<s.length()+1;i++){
        //     for(int j=0;j<p.length()+1;j++){
        //     cout<<match[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return match[s.length()][p.length()];
    }
};
