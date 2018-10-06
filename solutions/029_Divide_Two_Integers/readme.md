# 29. Divide Two Integers

## 简析

模拟整除运算，不准使用乘除。数据范围int32，结果越界就输出边界

## 方法：循环减代替整除

先不考虑越界，直接用循环减除数，发现会超时。可以用位操作快速（指数级增长）增大除数，同时位移整除结果步进，加快被除数被减小的速度。最后再一步步快速减小除数，直到被除数被减到小于除数;

考虑越界有两种做法：

1. 对所有超出边界的情况作特殊处理；
2. 直接强制使用long long，输出时再判断越界。

**我的代码：**

```cpp
class Solution {
public:
    int divide(int dividend, int divisor) {
        int sgn=0,res=0;
        if(dividend==INT_MIN){
            if(divisor==-1) return INT_MAX;
            else if(divisor==1) return INT_MIN;
        }
        if(divisor==INT_MIN) {
            if(dividend==INT_MIN)return 1;
            else return 0;
        }
        if((dividend<0)^(divisor<0)){
            sgn=1;
        }
        divisor=abs(divisor);
        if(dividend==INT_MIN){
            dividend=INT_MAX;
            dividend=dividend-divisor+1;
            res++;
        }else{
            dividend=abs(dividend);
        }
        int level=1,divisor_tmp=divisor;
        while(dividend>=divisor){
            while((divisor_tmp<0x3FFFFFFF)&&(dividend>=(divisor_tmp<<1))){
                divisor_tmp=divisor_tmp<<1;
                level=level<<1;
            }
            dividend-=divisor_tmp;
            res+=level;
            while((divisor_tmp)&&(dividend<divisor_tmp)){
                divisor_tmp=divisor_tmp>>1;
                level=level>>1;
            }
        }
        if(sgn)return -res;
        else return res;
    }
};
```
