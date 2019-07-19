// According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."
//
// Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):
//
//
// 	Any live cell with fewer than two live neighbors dies, as if caused by under-population.
// 	Any live cell with two or three live neighbors lives on to the next generation.
// 	Any live cell with more than three live neighbors dies, as if by over-population..
// 	Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
//
//
// Write a function to compute the next state (after one update) of the board given its current state. The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously.
//
// Example:
//
//
// Input: 
// [
//   [0,1,0],
//   [0,0,1],
//   [1,1,1],
//   [0,0,0]
// ]
// Output: 
// [
//   [0,0,0],
//   [1,0,1],
//   [0,1,1],
//   [0,1,0]
// ]
//
//
// Follow up:
//
//
// 	Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.
// 	In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?
//
//


class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int imax=board.size();
        if(imax==0) return;
        int jmax=board[0].size();
        if(jmax==0) return;
        for(int i = 0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                int count=0;
                for(int k=max(i-1,0);k<min(i+2,imax);k++){
                    for(int l=max(j-1,0);l<min(j+2,jmax);l++){
                        count+=board[k][l]&1;
                    }
                }
                if(count == 3 || (count ==4 && board[i][j]&1==1)) board[i][j]|=0x02;
            }
        }
        for(int i = 0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                board[i][j]=board[i][j]>>1;
            }
        }
    }
};
