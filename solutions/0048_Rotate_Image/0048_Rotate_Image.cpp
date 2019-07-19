// You are given an n x n 2D matrix representing an image.
//
// Rotate the image by 90 degrees (clockwise).
//
// Note:
//
// You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.
//
// Example 1:
//
//
// Given input matrix = 
// [
//   [1,2,3],
//   [4,5,6],
//   [7,8,9]
// ],
//
// rotate the input matrix in-place such that it becomes:
// [
//   [7,4,1],
//   [8,5,2],
//   [9,6,3]
// ]
//
//
// Example 2:
//
//
// Given input matrix =
// [
//   [ 5, 1, 9,11],
//   [ 2, 4, 8,10],
//   [13, 3, 6, 7],
//   [15,14,12,16]
// ], 
//
// rotate the input matrix in-place such that it becomes:
// [
//   [15,13, 2, 5],
//   [14, 3, 4, 1],
//   [12, 6, 8, 9],
//   [16, 7,10,11]
// ]
//
//


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int im_last,jm_last,im,jm,tmp2,tmp1;
        for(int i=0;i<n/2;i++){
            for(int j=i;j<n-i-1;j++){
                //cout<<"i:"<<i<<"j:"<<j<<endl;
                im_last=i;
                jm_last=j;
                tmp2=matrix[im_last][jm_last];
                for(int k=0;k<4;k++){
                    jm=n-im_last-1;
                    im=jm_last;
                    jm_last=jm;
                    im_last=im;
                    //cout<<"im:"<<im<<"jm:"<<jm<<"val:"<<tmp2<<endl;
                    tmp1=matrix[im][jm];
                    matrix[im][jm]=tmp2;
                    tmp2=tmp1;
                }
                
            }
        }
    }
};
