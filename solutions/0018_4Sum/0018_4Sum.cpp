// Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
//
// Note:
//
// The solution set must not contain duplicate quadruplets.
//
// Example:
//
//
// Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
//
// A solution set is:
// [
//   [-1,  0, 0, 1],
//   [-2, -1, 1, 2],
//   [-2,  0, 0, 2]
// ]
//
//


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if(nums.size()<4)return res;
        std::sort(nums.begin(),nums.end());
        int left,right;
        int v;
        for(int i=0;i<nums.size()-3;i++){
            while(i&&(nums[i]==nums[i-1])&&(++i<nums.size()-3));
            for(int j=i+1;j<nums.size()-2;j++){
                left=j+1;
                right=nums.size()-1;
                while((nums[j]==nums[j-1])&&(j>i+1))
                    if(++j>nums.size()-2) left=right;
                    else left=j+1;
                while(left<right){
                    v=nums[i]+nums[j]+nums[left]+nums[right];
                    if(v>target){
                        right--;
                        while(nums[right]==nums[right+1])
                            if(left>--right) break;
                    }else if(v<target){
                        left++;
                        while(nums[left]==nums[left-1]) 
                            if(++left>right) break;
                    }else{
                        res.push_back({nums[i],nums[j],nums[left],nums[right]});
                        right--;
                        while(nums[right]==nums[right+1])
                            if(left>--right) break;
                    }
                }
            }
        }
        return res;
    }
};
