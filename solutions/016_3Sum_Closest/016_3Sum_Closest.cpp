// Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
//
// Example:
//
//
// Given array nums = [-1, 2, 1, -4], and target = 1.
//
// The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
//
//


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size()<3)return 0;
        std:sort(nums.begin(),nums.end());
        int left,right;
        int vmin=nums[0]+nums[1]+nums[2];
        int v,dv;
        for(int i=0;i<nums.size()-2;i++){
            left=i+1;
            right=nums.size()-1;
            while(left<right){
                v=nums[i]+nums[left]+nums[right];
                dv=v-target;
                if(dv>0){
                    right--;    
                }else if(dv<0){
                    left++;
                }else{
                    return target;
                }
                
                if(abs(dv)<abs(vmin-target)) vmin=v;
            }
        }
        return vmin;
    }
};
