// Given a string S and a string T, count the number of distinct subsequences of S which equals T.
//
// A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
//
// Example 1:
//
//
// Input: S = "rabbbit", T = "rabbit"
// Output: 3
// Explanation:
//
// As shown below, there are 3 ways you can generate "rabbit" from S.
// (The caret symbol ^ means the chosen letters)
//
// rabbbit
// ^^^^ ^^
// rabbbit
// ^^ ^^^^
// rabbbit
// ^^^ ^^^
//
//
// Example 2:
//
//
// Input: S = "babgbag", T = "bag"
// Output: 5
// Explanation:
//
// As shown below, there are 5 ways you can generate "bag" from S.
// (The caret symbol ^ means the chosen letters)
//
// babgbag
// ^^ ^
// babgbag
// ^^    ^
// babgbag
// ^    ^^
// babgbag
//   ^  ^^
// babgbag
//     ^^^
//
//


class Solution {
public:
    int numDistinct(string s, string t) {
        if(t.length()>s.length()) return 0;
        int ways[t.length()+1][s.length()+1]={0};
        for(int j=0;j<s.length()+1;j++){
            ways[0][j]=1;
        }
        for(int i=1;i<t.length()+1;i++)
            for(int j=i;j<s.length()+1;j++){
                if(t[i-1]==s[j-1]) ways[i][j]=ways[i-1][j-1]+ways[i][j-1];
                else ways[i][j]=ways[i][j-1];
            }
        return ways[t.length()][s.length()];
    }
};
