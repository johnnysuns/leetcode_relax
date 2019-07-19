// We are playing the Guess Game. The game is as follows:
//
// I pick a number from 1 to n. You have to guess which number I picked.
//
// Every time you guess wrong, I'll tell you whether the number I picked is higher or lower.
//
// However, when you guess a particular number x, and you guess wrong, you pay $x. You win the game when you guess the number I picked.
//
// Example:
//
//
// n = 10, I pick 8.
//
// First round:  You guess 5, I tell you that it's higher. You pay $5.
// Second round: You guess 7, I tell you that it's higher. You pay $7.
// Third round:  You guess 9, I tell you that it's lower. You pay $9.
//
// Game over. 8 is the number I picked.
//
// You end up paying $5 + $7 + $9 = $21.
//
//
// Given a particular n ≥ 1, find out how much money you need to have to guarantee a win.


class Solution {
public:
    int getMoneyAmount(int n) {
        /*DP solution*/
        const int size=n+3;
        int s[size][size];
        int min_cost,tmp_cost;
        for(int i=0;i<n+1;i++){
            s[i+1][i]=0;
            s[i][i]=0;
            s[i][i+1]=i;
            s[i][i+2]=i+1;
        }
        for(int i=n-3;i>0;i--){
            //cout<<"i:"<<i<<endl;
            for(int j=i+3;j<n+1;j++){
                min_cost=max(s[i][i],s[i+1][j])+i;
                for(int k=i;k<j+1;k++){
                    tmp_cost=max(s[i][k-1],s[k+1][j])+k;
                    //cout<<"i:"<<i<<"j:"<<j<<"k"<<k<<":: "<<s[k+1][j]<<endl;
                    if(tmp_cost<min_cost) min_cost=tmp_cost;
                }
                s[i][j]=min_cost;
            }
        }
        return s[1][n];
     }
};
