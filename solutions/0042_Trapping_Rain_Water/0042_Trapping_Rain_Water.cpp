// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
//
//
// The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!
//
// Example:
//
//
// Input: [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
//


class Solution {
public:
    int trap(vector<int>& height) {
        int l=0;
        int r=height.size()-1;
        int l_tmp, r_tmp;
        int res=0;
        while(l<r){
            //find next level
            if(height[l]>height[r]){
                r_tmp=r-1;
                while(r_tmp>l && height[r_tmp]<height[r]){
                    res+=height[r]-height[r_tmp];
                    r_tmp--;
                }
                r=r_tmp;
            }else{
                l_tmp=l+1;
                while(l_tmp<r && height[l_tmp]<height[l]){
                    res+=height[l]-height[l_tmp];
                    l_tmp++;
                }
                l=l_tmp;
            }
            cout<<"l:"<<l<<" r:"<<r<<endl;
        }
        return res;
    }
};
