/*******************************************************************************
  *FileName:    main.cpp
  *Author:      Johnny Sun
  *Version:     1.0
  *Date:        2018.09.25
  *Description:

*******************************************************************************/
 #include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cstring>
#include <assert.h>

using namespace std;

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
string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
            result.push_back(currentChar);
        }
    }
    return result;
}

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    std::ifstream in("../input.txt");
    std::cin.rdbuf(in.rdbuf());
    while (getline(cin, line)) {
        string s = stringToString(line);
        getline(cin, line);
        int numRows = stringToInteger(line);

        string ret = Solution().convert(s, numRows);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}