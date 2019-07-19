// Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.
//
// Example 1:
//
//
// Input: num1 = "2", num2 = "3"
// Output: "6"
//
// Example 2:
//
//
// Input: num1 = "123", num2 = "456"
// Output: "56088"
//
//
// Note:
//
//
// 	The length of both num1 and num2 is < 110.
// 	Both num1 and num2 contain only digits 0-9.
// 	Both num1 and num2 do not contain any leading zero, except the number 0 itself.
// 	You must not use any built-in BigInteger library or convert the inputs to integer directly.
//
//


class Solution {
public:
    string multiply(string num1, string num2) {
        string res(num1.length()+num2.length(),0);
        int last=num1.length()+num2.length()-1;
        int start=0;
        if(num1.length()==0||num2.length()==0) return "";
        else if(num1=="0"||num2=="0") return "0";
        for(int i=0;i<num1.length();i++){
            num1[i]-='0';
        }
        for(int i=0;i<num2.length();i++){
            num2[i]-='0';
        }
        for(int i=num2.length()-1;i>-1;i--){
            for(int j = num1.length()-1; j>-1;j--){
                res[i+1+j]+=num2[i]*num1[j];
                if(res[i+1+j]>9){
                    res[i+j]+=res[i+1+j]/10;
                    res[i+1+j]%=10;
                }
            }
        }
        int i=0;
        for(;i<res.length();i++){
            if(res[i]!=0){
                start=i;
                break;
            }
            
        }
        for(;i<res.length();i++){
            //cout<<(int)res[i]<<endl;
            res[i]+='0';
        }
        
        return res.substr(start,res.length()-start);
    }
};
