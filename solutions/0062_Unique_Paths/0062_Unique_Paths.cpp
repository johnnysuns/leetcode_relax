// A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
//
// The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
//
// How many possible unique paths are there?
//
//
// Above is a 7 x 3 grid. How many possible unique paths are there?
//
// Note: m and n will be at most 100.
//
// Example 1:
//
//
// Input: m = 3, n = 2
// Output: 3
// Explanation:
// From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
// 1. Right -> Right -> Down
// 2. Right -> Down -> Right
// 3. Down -> Right -> Right
//
//
// Example 2:
//
//
// Input: m = 7, n = 3
// Output: 28
//


class Solution {
public:
    int uniquePaths(int m, int n) {
        long long ways[n+2][m+2]={0};
        memset(ways,0,sizeof(ways));
        ways[0][1]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                ways[i][j]=ways[i-1][j]+ways[i][j-1];
            }
        }
        return ways[n][m];
    }
};
