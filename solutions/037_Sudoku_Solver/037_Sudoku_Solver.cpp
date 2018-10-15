// Write a program to solve a Sudoku puzzle by filling the empty cells.
//
// A sudoku solution must satisfy all of the following rules:
//
//
// 	Each of the digits 1-9 must occur exactly once in each row.
// 	Each of the digits 1-9 must occur exactly once in each column.
// 	Each of the the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
//
//
// Empty cells are indicated by the character '.'.
//
//
// A sudoku puzzle...
//
//
// ...and its solution numbers marked in red.
//
// Note:
//
//
// 	The given board contain only digits 1-9 and the character '.'.
// 	You may assume that the given Sudoku puzzle will have a single unique solution.
// 	The given board size is always 9x9.
//
//


class Solution {
#define N 10
public:
    int getBlock(int i, int j){
        return i / 3 * 3 + j / 3;
    }
    void print(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
        
    //get available val of current cell in block
    void getAvailableValBlock(int checked[3][9][N], vector<int> &val, int block_index){
        for(int i=1;i<N;i++){
            //cout<<"checked[2][block_index]["<<i<<"]= "<<checked[2][block_index][i]<<endl;
            if(checked[2][block_index][i]==0){
                val.push_back(i);
            }
        }
    }
    
    bool getNextEmptyCell(vector<vector<char>>& board, int si, int sj, int &resi, int &resj){
        if(++sj==9){
            si++;
            sj=0;
        }
        while(si!=9){
            if(board[si][sj]=='.'){
                resi=si;
                resj=sj;
                return true;
            }
            if(++sj==9){
                si++;
                sj=0;
            }
        }
        return false;
    }
    
    // the cell is blank before and after this function.
    bool nextCellDFS(vector<vector<char>>& board, int checked[3][9][N], int i, int j){
        vector<int> vals;//TODO: vector here can be optimized to avoid sarch val every time
        int fill_once=0;
        int next_i;
        int next_j;
        bool not_final=true;
        int block_index = getBlock(i,j);
        not_final = getNextEmptyCell(board, i, j, next_i, next_j);

        getAvailableValBlock(checked, vals, block_index);
//cout<<"vals.size():"<<vals.size()<<" block_index: "<<block_index<<endl;
        static int pc=0;
//if(++pc>4200)print(board);
        for(int k=0;k<vals.size();k++){
            if(isFillinableRowCol(board, checked, i, j, vals[k])){
                //fill in and continue to search next cell;
//cout<<"filling ["<<i<<", "<<j<<"] with "<< vals[k] <<" next ["<<next_i<<", "<<next_j<<"]"<<endl;
                fill_once=1;
                if(not_final) {
                    board[i][j]=vals[k]+'0';
                    checked[2][block_index][vals[k]]=1;
                    checked[1][j][vals[k]]=1;
                    checked[0][i][vals[k]]=1;
                    if(nextCellDFS(board, checked, next_i, next_j)) return true;
                    //backtracking
                    board[i][j]='.';
                    checked[2][block_index][vals[k]]=0;
                    checked[1][j][vals[k]]=0;
                    checked[0][i][vals[k]]=0;
                }else{
                    board[i][j]=vals[k]+'0';
                    checked[2][block_index][vals[k]]=1;
                    checked[1][j][vals[k]]=1;
                    checked[0][i][vals[k]]=1;
                    return true;
                }
            }
        }

        return false;
    }
    //judge if a value fillable according to row && colum
    bool isFillinableRowCol(vector<vector<char>>& board, int checked[3][9][N],int vi, int vj, int val){
        //row check
        if(checked[0][vi][val]) return false;
        //col check
        if(checked[1][vj][val]) return false;
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        int checked[3][9][N]={0};//row/col/block check exist
        int i=0;
        int j=0;
        //init check list
        for(;i<9;i++){
            for(j=0;j<9;j++){
                if(board[i][j]!='.'){
                    checked[0][i][board[i][j]-'0']=1;
                    checked[1][j][board[i][j]-'0']=1;
                    checked[2][getBlock(i,j)][board[i][j]-'0']=1;
                }
            }
        }
        //check cell
        if(getNextEmptyCell(board, 0, -1, i, j)){
            nextCellDFS(board, checked, i, j);
        }
    }
};
