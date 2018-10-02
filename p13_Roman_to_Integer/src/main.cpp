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
    int romanToInt(string s) {
        int res=0;
        switch(s[0]){
            case 'M':
                res+=1000;
                break;
            case 'D':
                res+=500;
                break;
            case 'C':
                res+=100;
                break;
            case 'L':
                res+=50;
                break;
            case 'X':
                res+=10;
                break;
            case 'V':
                res+=5;
                break;
            case 'I':
                res+=1;
                break;
            default:
                break;
        }
        for(int i=1;i<s.length();i++){
            switch(s[i]){
                case 'M':
                    if(s[i-1]=='C') res+=800;
                    else res+=1000;
                    break;
                case 'D':
                    if(s[i-1]=='C') res+=300;
                    else res+=500;
                    break;
                case 'C':
                    if(s[i-1]=='X') res+=80;
                    else res+=100;
                    break;
                case 'L':
                    if(s[i-1]=='X') res+=30;
                    else res+=50;
                    break;
                case 'X':
                    if(s[i-1]=='I') res+=8;
                    else res+=10;
                    break;
                case 'V':
                    if(s[i-1]=='I') res+=3;
                    else res+=5;
                    break;
                case 'I':
                    res+=1;
                    break;
                default:
                    break;
            }
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
        string s = stringToString(line);

        int ret = Solution().romanToInt(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}