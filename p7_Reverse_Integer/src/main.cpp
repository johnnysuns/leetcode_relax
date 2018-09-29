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
    int reverse(int x) {
        if(x>0x7fffffff||x<-2147483648) return 0;

    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    std::ifstream in("../input.txt");
    std::cin.rdbuf(in.rdbuf());
    while (getline(cin, line)) {
        int x = stringToInteger(line);

        int ret = Solution().reverse(x);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}