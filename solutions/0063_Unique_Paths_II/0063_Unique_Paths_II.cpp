// A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
//
// The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
//
// Now consider if some obstacles are added to the grids. How many unique paths would there be?
//
//
//
// An obstacle and empty space is marked as 1 and 0 respectively in the grid.
//
// Note: m and n will be at most 100.
//
// Example 1:
//
//
// Input:
// [
//   [0,0,0],
//   [0,1,0],
//   [0,0,0]
// ]
// Output: 2
// Explanation:
// There is one obstacle in the middle of the 3x3 grid above.
// There are two ways to reach the bottom-right corner:
// 1. Right -> Right -> Down -> Down
// 2. Down -> Down -> Right -> Right
//
//


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        //output
        /*
        for(int k=0;k<obstacleGrid.size();k++)
        {
            for(int l=0;l<obstacleGrid[0].size();l++)
                cout<<obstacleGrid[k][l]<<" ";
            cout<<endl;
        }
        cout<<endl;
        */
        //update top & left line
        if(obstacleGrid.size()&&obstacleGrid[0].size()){
            obstacleGrid[0][0]=obstacleGrid[0][0]==0;
            for(int j=1;j<obstacleGrid[0].size();j++){
                if(obstacleGrid[0][j]) obstacleGrid[0][j]=0;
                else obstacleGrid[0][j]=obstacleGrid[0][j-1];
            }
            for(int i=1;i<obstacleGrid.size();i++){
                if(obstacleGrid[i][0]) obstacleGrid[i][0]=0;
                else obstacleGrid[i][0]=obstacleGrid[i-1][0];
            }
        }else{
            return 0;
        }
        //update inside
        for(int i=1;i<obstacleGrid.size();i++){
            for(int j = 1; j<obstacleGrid[0].size(); j++){
                if(obstacleGrid[i][j]==1){
                    obstacleGrid[i][j]=0;
                }else{
                    obstacleGrid[i][j]=obstacleGrid[i-1][j]+obstacleGrid[i][j-1];
                }
            }
            //output
            /*
            for(int k=0;k<obstacleGrid.size();k++)
            {
                for(int l=0;l<obstacleGrid[0].size();l++)
                    cout<<obstacleGrid[k][l]<<" ";
                cout<<endl;
            }
            cout<<endl;
            */
        }
        return obstacleGrid[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
    }
};
