// The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
//
//
//
// Given an integer n, return the number of distinct solutions to the n-queens puzzle.
//
// Example:
//
//
// Input: 4
// Output: 2
// Explanation: There are two distinct solutions to the 4-queens puzzle as shown below.
// [
//  [".Q..",  // Solution 1
//   "...Q",
//   "Q...",
//   "..Q."],
//
//  ["..Q.",  // Solution 2
//   "Q...",
//   "...Q",
//   ".Q.."]
// ]
//
//


class Solution {
public:
    void printchessboard(vector<vector<int>> &checkdata,int step){
        cout<<"step:"<<step<<endl;
        const int n=checkdata.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<checkdata[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    
    void conquer(vector<vector<int>> &checkdata, int step, int i, const int isconquer){
        const int n=checkdata.size();
        for(int j=step;j<n;j++){
            //checkdata[step][j]+=isconquer;//no need to search
            checkdata[j][i]+=isconquer;
        }
        int diff=i-step;//↘
        if(diff<0){//down left
            //for(int j=-diff;j<n;j++){
            for(int j=step;j<n;j++){
                checkdata[j][j+diff]+=isconquer;
            }
        }else{//up right
            for(int j=step;j<n-diff;j++){
                checkdata[j][diff+j]+=isconquer;
            }
        }
        int sum=i+step;//↙
        if(sum>=n){//down right
            //for(int j=sum-n+1;j<n;j++){
            for(int j=step;j<n;j++){
                checkdata[j][sum-j]+=isconquer;
            }
        }else{//up left
            for(int j=step;j<sum+1;j++){
                checkdata[j][sum-j]+=isconquer;
            }
        }
    }
    
    void solveNQueens(int &res, vector<vector<int>> &checkdata, int step) {   
        const int n=checkdata.size();
        //printchessboard(checkdata,step);
        if(step==n){//output
            res++;
        }else{
            for(int i=0;i<n;i++){
                if(checkdata[step][i]==0){//fill in
                    conquer(checkdata, step, i, 1);
                    solveNQueens(res, checkdata, step+1);
                    conquer(checkdata, step, i, -1);
                }
            }
        }
    }
    
    int totalNQueens(int n) {
        int res=0;
        vector<vector<int>> checkdata;
        for(int i=0;i<n;i++){
            vector<int> checkdata_(n,0);
            checkdata.emplace_back(checkdata_);
        }
        solveNQueens(res, checkdata, 0);
        return res;
    }
};
