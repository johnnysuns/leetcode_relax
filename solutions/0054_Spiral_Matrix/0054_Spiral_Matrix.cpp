// Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
//
// Example 1:
//
//
// Input:
// [
//  [ 1, 2, 3 ],
//  [ 4, 5, 6 ],
//  [ 7, 8, 9 ]
// ]
// Output: [1,2,3,6,9,8,7,4,5]
//
//
// Example 2:
//
// Input:
// [
//   [1, 2, 3, 4],
//   [5, 6, 7, 8],
//   [9,10,11,12]
// ]
// Output: [1,2,3,4,8,12,11,10,9,5,6,7]
//


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.size()==0)return res;
        else if(matrix[0].size()==0)return res;
        int m_rows=matrix.size();
        int n_cols=matrix[0].size();
        int i=0;
        int j=0;
        for(int up_row=0;up_row<(min(m_rows,n_cols)+1)/2;up_row++){
            if((up_row==n_cols-up_row-1)){ //one col
                for(i=up_row;i<=m_rows-up_row-1;i++){//⬇
                    cout<<"1push⬇:"<<matrix[i][n_cols-up_row-1]<<endl;
                    res.emplace_back(matrix[i][n_cols-up_row-1]);
                }
            }else if(m_rows-up_row-1==up_row){//one row
                for(j=up_row;j<=n_cols-up_row-1;j++){//->
                    cout<<"1push->:"<<matrix[up_row][j]<<endl;
                    res.emplace_back(matrix[up_row][j]);
                }
            }else{//at least 2 cols && 2 rows
                for(j=up_row;j<n_cols-up_row-1;j++){//->
                    cout<<"push->:"<<matrix[up_row][j]<<endl;
                    res.emplace_back(matrix[up_row][j]);
                }
                for(i=up_row;i<m_rows-up_row-1;i++){//⬇
                    cout<<"push⬇:"<<matrix[i][n_cols-up_row-1]<<endl;
                    res.emplace_back(matrix[i][n_cols-up_row-1]);
                }
                for(j=n_cols-up_row-1;j>up_row;j--){//<-
                    cout<<"push<-:"<<matrix[m_rows-up_row-1][j]<<endl;
                    res.emplace_back(matrix[m_rows-up_row-1][j]);
                }
                for(i=m_rows-up_row-1;i>up_row;i--){//⬆
                    cout<<"push:⬆"<<matrix[i][up_row]<<endl;
                    res.emplace_back(matrix[i][up_row]);
                }
            }
        }
        //cout<<endl;
        return res;
    }
};
