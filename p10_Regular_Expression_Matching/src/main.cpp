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
    bool isMatch(string s, string p) {
        int state[s.length()+1][p.length()+1]={0};
        int n=s.length()+1;
        int m=p.length()+1;
        memset(state,0,sizeof(state));
        state[0][0]=1;
        if(m>1) {
            //state[0][1]=(p[0]=='*')||(p[0]=='.');
            if(n>1)state[1][1]=(s[0]==p[0])||(p[0]=='.');
        }
        for (int j = 2;j<m;j++){
            state[0][j]=((p[j-1]=='*')&&(state[0][j-1]||state[0][j-2]));
        }

        for (int i = 1;i<n;i++)
            for (int j = 2;j<m;j++){
                if((s[i-1]==p[j-1])||(p[j-1]=='.')){
                    state[i][j]=state[i-1][j-1];
                //}else if(p[j-1]=='.'){
                //    state[i][j]=state[i-1][j-1];
                }else if (p[j-1]=='*'){
                    if((s[i-1]!=p[j-2])&&(p[j-2]!='.')){//*zero
                        state[i][j]=state[i][j-2];
                    }else//* not empty
                    {
                        state[i][j]=state[i][j-2]||state[i][j-1]||state[i-1][j];
                    }
                }
            }
        return state[s.length()][p.length()];
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
        } else if(input[i]=='"'){

        } else {
            result.push_back(currentChar);
        }
    }
    return result;
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    std::ifstream in("../input.txt");
    std::cin.rdbuf(in.rdbuf());
    while (getline(cin, line)) {
        string s = stringToString(line);
        getline(cin, line);
        string p = stringToString(line);

        bool ret = Solution().isMatch(s, p);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}