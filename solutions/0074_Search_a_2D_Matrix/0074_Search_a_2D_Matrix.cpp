// Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
//
//
// 	Integers in each row are sorted from left to right.
// 	The first integer of each row is greater than the last integer of the previous row.
//
//
// Example 1:
//
//
// Input:
// matrix = [
//   [1,   3,  5,  7],
//   [10, 11, 16, 20],
//   [23, 30, 34, 50]
// ]
// target = 3
// Output: true
//
//
// Example 2:
//
//
// Input:
// matrix = [
//   [1,   3,  5,  7],
//   [10, 11, 16, 20],
//   [23, 30, 34, 50]
// ]
// target = 13
// Output: false
//


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int> rows;
        if(matrix.size()==0)return false;
        if(matrix[0].size()==0)return false;
        for(auto &row : matrix){
            rows.push_back(row[0]);
        }
        auto row_it = upper_bound(rows.begin(),rows.end(),target);
        if(row_it==rows.begin()) return false;
        row_it--;
        cout<<"row first:"<<*row_it<<endl;
        return binary_search(matrix[row_it-rows.begin()].begin(),matrix[row_it-rows.begin()].end(),target);
    }
};
