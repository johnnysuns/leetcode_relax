// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
//
//
// P   A   H   N
// A P L S I I G
// Y   I   R
//
//
// And then read line by line: "PAHNAPLSIIGYIR"
//
// Write the code that will take a string and make this conversion given a number of rows:
//
//
// string convert(string s, int numRows);
//
// Example 1:
//
//
// Input: s = "PAYPALISHIRING", numRows = 3
// Output: "PAHNAPLSIIGYIR"
//
//
// Example 2:
//
//
// Input: s = "PAYPALISHIRING", numRows = 4
// Output: "PINALSIGYAHRPI"
// Explanation:
//
// P     I    N
// A   L S  I G
// Y A   H R
// P     I
//


class Solution {
public:
    string convert(string s, int numRows) {
        numRows=min(numRows,(int)s.length());
        string *sbuf=new string[numRows];
        int i=0;
        int j=0;
        int iszig=1;
        if(s.length()==0) return "";
        if (numRows<2) return s;
        while(i<s.length())
        {
            sbuf[j].append(1,s[i]);

            if(iszig){
                if(++j==numRows-1) iszig=0;;
            }else{
                if(--j==0) iszig=1;
            }
            i++;
        }
        string sres;
        for (int i = 0; i < numRows; ++i){
            sres.append(sbuf[i]);
        }
        delete[] sbuf;
        return sres;
    }
};
