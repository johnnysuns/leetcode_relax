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
#include <stack>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        int i=0;
        int x_=0;
        int dig;
        if (x<0||x%10==0)return false;
        while(x_<x) {
            dig=x%10;
            x/=10;
            x_=x_*10+dig;
        }

        if((x==x_)||(x_/10==x)){
            return true;
        }
        return false;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    std::ifstream in("../input.txt");
    std::cin.rdbuf(in.rdbuf());
    while (getline(cin, line)) {
        int x = stringToInteger(line);

        bool ret = Solution().isPalindrome(x);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}