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
    string intToRoman(int num) {
        string M[]={"","M","MM","MMM"};
        string C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string V[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        int index=num/1000;
        num%=1000;
        string res=M[index];
        index=num/100;
        num%=100;
        res+=C[index];
        index=num/10;
        num%=10;
        res+=X[index];
        res+=X[num];
        return res;
#if 0
        string res;
        //while(num){
        if(num>999){
            do{
                num-=1000;
                res+='M';
            }while(num>999);
        }
        if(num>899){
            num-=900;
            res+="CM";
        }
        if(num>499){
            num-=500;
            res+='D';
            while(num>99){
                num-=100;
                res+='C';
            }
        }
        if(num>399){
            num-=400;
            res+="CD";
        }
        if(num>99){
            do{
                num-=100;
                res+='C';
            }while(num>99);
        }
        if(num>89){
            num-=90;
            res+="XC";
        }
        if(num>49){
            num-=50;
            res+='L';
            while(num>9){
                num-=10;
                res+='X';
            }
        }
        if(num>39){
            num-=40;
            res+="XL";
        }
        if(num>9){
            do{
                num-=10;
                res+='X';
            }while(num>9);
        }
        if(num>8){
            num-=9;
            res+="IX";
        }
        if(num>4){
            num-=5;
            res+='V';
            while(num>0){
                num-=1;
                res+='I';
            }
        }
        if(num>3){
            num-=4;
            res+="IV";
        }
        if(num>0){
            do{
                num-=1;
                res+='I';
            }while(num>0);
        }

        //}
        return res;
#endif
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
        int num = stringToInteger(line);

        string ret = Solution().intToRoman(num);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}