// Given two binary strings, return their sum (also a binary string).
//
// The input strings are both non-empty and contains only characters 1 or 0.
//
// Example 1:
//
//
// Input: a = "11", b = "1"
// Output: "100"
//
// Example 2:
//
//
// Input: a = "1010", b = "1011"
// Output: "10101"
//


class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        if(a.length()<b.length()){
            res=a;
            a=b;
            b=res;
        }
        res=a;
        
        int aindex=0;
        for(int i=0;i<b.length();i++){
            aindex=a.length()-1-i;
            res[aindex]=a[aindex]+b[b.length()-1-i]-'0';
        }
        
        for(int i=res.length()-1;i>=0;i--){
            if(res[i]>='2'){
                res[i]-=2;
                if(i){
                    res[i-1]++;
                }else{
                    res="1"+res;
                }
            }
        }
        return res;
    }
};
