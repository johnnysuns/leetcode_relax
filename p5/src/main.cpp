/*******************************************************************************
  *FileName:    main.cpp
  *Author:      Johnny Sun
  *Version:     1.0
  *Date:        2018.09.24
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
private:

public:
    string longestPalindrome(string s) {
        int i=0;
        int max_len=0;
        int max_start=0;
        int cur_len=0;
        int left,right;
        int a=s.length();

        while(i<a) {
            left=i,right=i;
            while(left>=0 && right<=a && s[left]==s[right]){
                left--;
                right++;
            }

            cur_len=right-left-1;
            if(cur_len>max_len){
                max_len=cur_len;
                max_start=left+1;
            }
            cur_len=0;
            left=i,right=i+1;
            while(left>=0 && right<=a && s[left]==s[right]){
                left--;
                right++;
            }
            cur_len=right-left-1;
            if(cur_len>max_len){
                max_len=cur_len;
                max_start=left+1;
            }
            cur_len=0;

            i++;
        }

        return s.substr(max_start,max_len);
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

        string ret = Solution().longestPalindrome(s);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
