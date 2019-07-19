# 91. Decode Ways  

## 简析

1-27是有效编码，求给定字符串有效分割方法。

需要注意的是，单个0不在编码中，而10和20则在编码中

## 方法：DP

状态空间：ways[i]，到i字符串长度为止可分割方法数

初始条件：ways[0] = 1; ways[1] = (s[0]是否为‘0’)

状态转移方程：

$$
ways[i]=S1+S2
$$

S1: s[i-1]作为一位有效编码的分割方法数（s[i-1]=='0'时为0）

S2: s[i-2],s[i-1]作为两位有效编码的分割方法数（1-27范围内有效）

快速判断1-27方法：

```cpp
s[i-2] == '1' || s[i-2] == '2' && s[i-1] < '7'
```

我在程序中使用了O(n)的空间，实际上，递推只需ways[i-1]和ways[i-2]两个数，类似斐波那契(Fibonacci)数列的递推，只需要两个变量即可。

**我的代码：**

```cpp
class Solution {
public:
    int numDecodings(string s) {
        int ways[s.length()+1];
        ways[0] = 1;
        ways[1] = (s[0]!='0');
        for(int i=2; i<s.length()+1; i++){
            ways[i]=((s[i-1] == '0')?(0):(ways[i-1]))+(((s[i-2] == '1' || s[i-2] == '2' && s[i-1] < '7'))?(ways[i-2]):(0));
        }
        return ways[s.length()];
    }
};
```
