// The count-and-say sequence is the sequence of integers with the first five terms as following:
//
//
// 1.     1
// 2.     11
// 3.     21
// 4.     1211
// 5.     111221
//
//
// 1 is read off as "one 1" or 11.
// 11 is read off as "two 1s" or 21.
// 21 is read off as "one 2, then one 1" or 1211.
//
// Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence.
//
// Note: Each term of the sequence of integers will be represented as a string.
//
//  
//
// Example 1:
//
//
// Input: 1
// Output: "1"
//
//
// Example 2:
//
//
// Input: 4
// Output: "1211"
//


class Solution {
public:
    string countAndSay(int n) {
        string res="1";
        string res_t="";
        int count;
        int k;
        char count_char;
        for(int i=0;i<n-1;i++){
            res_t="";
            //cout<<"i:"<<i<<" res:"<<res<<endl;
            for(int j=0;j<res.length();){
                k=j+1;
                count=1;
                while(k<res.length() && res[k]==res[j]){
                    count++;
                    k++;
                }
                count_char=count+'0';
                res_t=res_t+count_char+res[j];
                //cout<<"count:"<<count<<" char:"<<res[j]<<" k:"<<k<<" res.length()"<<res.length()<<endl;
                j=k;
            }
            res=res_t;
        }
        return res;
    }
};
