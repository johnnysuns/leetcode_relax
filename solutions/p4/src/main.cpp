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
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int mid = (nums1.size()+nums2.size()+1)/2;
        int bMin=0;
        vector<int> *a,*b;
        if(nums1.size()<nums2.size()) {
            a=&nums1;
            b=&nums2;
        } else {
            a=&nums2;
            b=&nums1;
        }
        int bMax=a->size();
        if(bMax==0){
            if(b->size()%2){
                return b->data()[b->size()/2];
            }else{
                return (b->data()[b->size()/2-1]+b->data()[b->size()/2])/2.0;
            }
        }

        double res=0;
        int i;
        int j;
        while(bMax>=bMin)
        {
            i = (bMin + bMax) / 2;
            j = mid - i;
            if((a->data()[i]<b->data()[j-1])&&(bMax!=bMin))
            {
                bMin=i+1;
            } else if((a->data()[i-1]>b->data()[j])&&(bMax!=bMin)) {
                bMax=i-1;
            }
            else{
                int aleft= i;
                int aright = a->size()-i-1;
                int bleft =j;
                int bright =b->size()-j-1;

                int maxleft;

                if (aleft==0){
                    maxleft=b->data()[j-1];
                }else if(bleft==0){
                    maxleft=a->data()[i-1];
                } else{
                    maxleft=max(a->data()[i-1],b->data()[j-1]);
                }

                int minright;
                if(aleft==a->size()){
                    minright=b->data()[j];
                }else if (bleft==b->size()){
                    minright=a->data()[i];
                }else{
                    minright=min(a->data()[i],b->data()[j]);
                }
                if ((a->size()+b->size())%2){
                    if (aleft+bleft>aright+bright){
                        return maxleft;
                    }else{
                        return minright;
                    }
                }
                return (maxleft+minright)/2.0;
            }
        }
        return res;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    std::ifstream in("../input.txt");
    std::cin.rdbuf(in.rdbuf());
    while (getline(cin, line)) {
        vector<int> nums1 = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> nums2 = stringToIntegerVector(line);

        double ret = Solution().findMedianSortedArrays(nums1, nums2);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}