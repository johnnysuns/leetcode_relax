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
#include <climits>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int i=0;
        int dig_count=0;
        long res=0;
        int rev=0;
        while(i<str.length())
        {
            switch(str[i])
            {
                case ' ':
                    if(dig_count){
                        i=str.length();
                    }else{
                        //donothing;
                    }
                    break;
                case '+':
                    if(dig_count){
                        i=str.length();
                    }else{
                        //donothing;
                    }
                    dig_count++;
                    break;
                case '-':
                    if(dig_count){
                        i=str.length();
                    }else{
                        rev=1-rev;
                    }
                    dig_count++;
                    break;
                case '0'...'9':
                    dig_count++;
                    res=res*10+str[i]-'0';
                    if(res>INT_MAX){
                        if(rev){
                            return INT_MIN;
                        }else {
                            return INT_MAX;
                        }
                    }
                    break;
                default:
                    //if(dig_count){
                    i=str.length();
                    //}else{
                    //   //donothing;
                    //}
                    break;
            }
            i++;
        }
        if(rev){
            return -res;
        }
        return res;
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

int main() {
    string line;
    std::ifstream in("../input.txt");
    std::cin.rdbuf(in.rdbuf());
    while (getline(cin, line)) {
        string str = stringToString(line);

        int ret = Solution().myAtoi(str);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}