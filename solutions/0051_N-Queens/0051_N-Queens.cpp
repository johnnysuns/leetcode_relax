// The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
//
//
//
// Given an integer n, return all distinct solutions to the n-queens puzzle.
//
// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
//
// Example:
//
//
// Input: 4
// Output: [
//  [".Q..",  // Solution 1
//   "...Q",
//   "Q...",
//   "..Q."],
//
//  ["..Q.",  // Solution 2
//   "Q...",
//   "...Q",
//   ".Q.."]
// ]
// Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above.
//
//


class Solution {
public:
    void printchessboard(vector<string> &checkboard,int step){
        cout<<"step:"<<step<<endl;
        const int n=checkboard.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<checkboard[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    
    void conquer(vector<vector<int>> &checkdata, vector<string> &checkboard, int step, int i, const int isconquer){
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
    
    void solveNQueens(vector<vector<string> > &res, vector<vector<int>> &checkdata, vector<string> &checkboard, int step) {   
        const int n=checkboard.size();
        //printchessboard(checkboard,step);
        if(step==n){//output
            res.emplace_back(checkboard);
        }else{
            for(int i=0;i<n;i++){
                if(checkdata[step][i]==0){//fill in
                    conquer(checkdata, checkboard, step, i, 1);
                    checkboard[step][i]='Q';
                    solveNQueens(res, checkdata, checkboard, step+1);
                    checkboard[step][i]='.';
                    conquer(checkdata, checkboard, step, i, -1);
                }
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string> > res;
        vector<string> checkboard(n, string(n, '.'));
        vector<vector<int>> checkdata;
        for(int i=0;i<n;i++){
            vector<int> checkdata_(n,0);
            checkdata.emplace_back(checkdata_);
        }
        solveNQueens(res, checkdata, checkboard, 0);
        return res;
    }
};
