// Implement pow(x, n), which calculates x raised to the power n (xn).
//
// Example 1:
//
//
// Input: 2.00000, 10
// Output: 1024.00000
//
//
// Example 2:
//
//
// Input: 2.10000, 3
// Output: 9.26100
//
//
// Example 3:
//
//
// Input: 2.00000, -2
// Output: 0.25000
// Explanation: 2-2 = 1/22 = 1/4 = 0.25
//
//
// Note:
//
//
// 	-100.0 < x < 100.0
// 	n is a 32-bit signed integer, within the range [−231, 231 − 1]
//
//


class Solution {
public:
    double myPow(double x, int n) {
        int patch=1;
        if(n<0) {
            x=1/x;
            if(n==INT_MIN){
                patch=x;
                n++;
            }
            n=-n;
            
        }else if(n==0){
            return 1;
        }
        //speed up by pow(x,2n)==pow(x,n)*pow(x,n)
        if(n&1){
            return patch*x*myPow(x, n-1);
        }else{
            return patch*myPow(x*x, n>>1);
        }
        // while(n--){
        //     res*=x;
        // }
        // return res;
    }
};
