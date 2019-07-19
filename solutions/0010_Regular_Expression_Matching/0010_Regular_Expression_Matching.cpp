// Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.
//
//
// '.' Matches any single character.
// '*' Matches zero or more of the preceding element.
//
//
// The matching should cover the entire input string (not partial).
//
// Note:
//
//
// 	s could be empty and contains only lowercase letters a-z.
// 	p could be empty and contains only lowercase letters a-z, and characters like . or *.
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
// p = "a*"
// Output: true
// Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
//
//
// Example 3:
//
//
// Input:
// s = "ab"
// p = ".*"
// Output: true
// Explanation: ".*" means "zero or more (*) of any character (.)".
//
//
// Example 4:
//
//
// Input:
// s = "aab"
// p = "c*a*b"
// Output: true
// Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore, it matches "aab".
//
//
// Example 5:
//
//
// Input:
// s = "mississippi"
// p = "mis*is*p*."
// Output: false
//
//


class Solution {
public:
    bool isMatch(string s, string p) {
        int state[s.length()+1][p.length()+1]={0};
        int n=s.length()+1;
        int m=p.length()+1;
        memset(state,0,sizeof(state));
        state[0][0]=1;
        if(m>1) {
            //state[0][1]=(p[0]=='*')||(p[0]=='.');
            if(n>1)state[1][1]=(s[0]==p[0])||(p[0]=='.');
        }
        for (int j = 2;j<m;j++){
            state[0][j]=((p[j-1]=='*')&&(state[0][j-1]||state[0][j-2]));
        }
        for (int i = 1;i<n;i++)
            for (int j = 2;j<m;j++){
                if((s[i-1]==p[j-1])||(p[j-1]=='.')){
                    state[i][j]=state[i-1][j-1];
                //}else if(p[j-1]=='.'){
                //    state[i][j]=state[i-1][j-1];
                }else if (p[j-1]=='*'){
                    if((s[i-1]!=p[j-2])&&(p[j-2]!='.')){//*zero
                        state[i][j]=state[i][j-2];
                    }else//* not empty
                    {
                        state[i][j]=state[i][j-2]||state[i][j-1]||state[i-1][j];
                    }
                }
            }
        return state[s.length()][p.length()];
    }
};
