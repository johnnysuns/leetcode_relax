// Given an array of non-negative integers, you are initially positioned at the first index of the array.
//
// Each element in the array represents your maximum jump length at that position.
//
// Your goal is to reach the last index in the minimum number of jumps.
//
// Example:
//
//
// Input: [2,3,1,1,4]
// Output: 2
// Explanation: The minimum number of jumps to reach the last index is 2.
//     Jump 1 step from index 0 to 1, then 3 steps to the last index.
//
// Note:
//
// You can assume that you can always reach the last index.
//


class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()<2)return 0;
        int steps[nums.size()]={0};
        //TOO SLOW
        // for(int i=0;i<nums.size();i++){
        //     for(int j=1;j<=nums[i];j++){
        //         if((i+j<nums.size())&&((steps[i]+1<steps[i+j])||(steps[i+j]==0))) 
        //             steps[i+j]=steps[i]+1;
        //     }
        // }
        // //for(int i=0;i<nums.size();i++) cout<<" "<<steps[i];
        // //cout<<endl;
        // return steps[nums.size()-1];
        list<int> open;
        open.push_back(0);
        while(nums.size()!=0){
            int i=open.front();
            if(i+nums[i]>=nums.size()-1) return steps[i]+1;
            for(int j=nums[i];j>0;j--){
                if(steps[i+j]==0) {
                    if(i+j>=nums.size()-1) return steps[i]+1;
                    steps[i+j]=steps[i]+1;
                    open.push_back(i+j);
                }
            }
            open.pop_front();
        }
        return steps[nums.size()-1];
    }
};
