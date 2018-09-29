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
    int lengthOfLongestSubstring(string s) {
        int check_exist[256]={0};
        int max_length = 0;
        int temp_length=0;
        for(int i=0;i<s.size();i++)
        {
            if(check_exist[s[i]])
            {
                if(temp_length>max_length)
                {
                    max_length=temp_length;
                }
                i=check_exist[s[i]];
                if(s.size()-i<max_length) break;
                memset(check_exist,0,sizeof(check_exist));
                check_exist[s[i]]=i+1;
                temp_length=0;
            } else
            {
                check_exist[s[i]]=i+1;//record last index
            }
            temp_length++;
        }
        if(temp_length>max_length) max_length=temp_length;
        return max_length;
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

        int ret = Solution().lengthOfLongestSubstring(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}