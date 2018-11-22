// Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
//
// Example:
//
//
// Input: 3
// Output:
// [
//  [ 1, 2, 3 ],
//  [ 8, 9, 4 ],
//  [ 7, 6, 5 ]
// ]
//
//


class Solution {
public:
    void output(vector<vector<int>> &a){
        for(int i=0;i<a.size();i++){
            for(int j=0;j<a[0].size();j++){
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n,0));
            
        int count=0;
        const int count_max=n*n;
        int i=0;//layer
        int j=0;
        while(count<count_max){
            j=i;
            while(j<n-i){//→
                res[i][j++]=++count;
            }
            j=i+1;
            while(j<n-1-i){//↓
                res[j++][n-1-i]=++count;
            }
            j=n-1-i;
            while(j>i){//←
                res[n-1-i][j--]=++count;
            }
            j=n-1-i;
            while(j>i){//↑
                res[j--][i]=++count;
            }
            i++;
            //cout<<i<<endl;
            //output(res);
        }
        return res;
    }
};
