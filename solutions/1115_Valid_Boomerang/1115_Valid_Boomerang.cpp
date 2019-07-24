// A boomerang is a set of 3 points that are all distinct and not in a straight line.
//
// Given a list of three points in the plane, return whether these points are a boomerang.
//
//  
//
// Example 1:
//
//
// Input: [[1,1],[2,3],[3,2]]
// Output: true
//
//
//
// Example 2:
//
//
// Input: [[1,1],[2,2],[3,3]]
// Output: false
//
//
//  
//
// Note:
//
//
// 	points.length == 3
// 	points[i].length == 2
// 	0 <= points[i][j] <= 100
//
//
//
//  
//


class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        int v1_x=points[1][0]-points[0][0];
        int v1_y=points[1][1]-points[0][1];
        int v2_x=points[2][0]-points[1][0];
        int v2_y=points[2][1]-points[1][1];
        int cross = v1_x*v2_y-v1_y*v2_x;
        if (cross!=0) return true;
        else return false;
    }
};
