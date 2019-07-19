// Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.
//
// Return the quotient after dividing dividend by divisor.
//
// The integer division should truncate toward zero.
//
// Example 1:
//
//
// Input: dividend = 10, divisor = 3
// Output: 3
//
// Example 2:
//
//
// Input: dividend = 7, divisor = -3
// Output: -2
//
// Note:
//
//
// 	Both dividend and divisor will be 32-bit signed integers.
// 	The divisor will never be 0.
// 	Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 231 − 1 when the division result overflows.
//
//


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
            //cout<<"**devidend:"<<dividend<<endl;
            while((divisor_tmp<0x3FFFFFFF)&&(dividend>=(divisor_tmp<<1))){
                divisor_tmp=divisor_tmp<<1;
                level=level<<1;
                //cout<<"++devidend:"<<dividend<<" divisor_tmp:"<<divisor_tmp<<endl;
            }
            //cout<<"res:"<<res<<" dividend:"<<dividend<<endl;
            dividend-=divisor_tmp;
            res+=level;
            //cout<<"start --divisor_tmp:"<<divisor_tmp << " dividend:"<<dividend<<endl;
            while((divisor_tmp)&&(dividend<divisor_tmp)){
                //cout<<"--devidend:"<<dividend<<" divisor_tmp:"<<divisor_tmp<<endl;
                divisor_tmp=divisor_tmp>>1;
                level=level>>1;
            }
        }
        if(sgn)return -res;
        else return res;
    }
};
