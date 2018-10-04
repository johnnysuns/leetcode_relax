# 375. Guess Number Higher or Lower II

## 方法：动态规划

- 状态空间：s[i,j],代表猜中区间[i,j]内数的最小的cost。

- 边界条件(两种情况)
  - 区间内只有一个数(j==i) 直接猜中，cost为0；
  - 区间内又两个数(j==i+1) 猜较小的数i
  - 三个数时(j==i+2)其实也能一步确定，猜中间数i+1。

- 状态转移方程：
  $$
  s[i][j]=\min_{k \in (i,j)} (max(s[i,k-1],s[k+1,j])+k,s[i][j])
  $$

- 边界处理

  直接对全状态使用一个公式可能存在越界情况，可以在循环边界上做限制，我这里直接采用扩大空间的方法，这样初始化和状态转移方程可以使用同一段代码而不用判断越界。初始边界里有j=i-1的情况。

## 我的源码：

```cpp
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
```