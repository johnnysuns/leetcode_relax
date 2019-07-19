// Given an array of non-negative integers, you are initially positioned at the first index of the array.
//
// Each element in the array represents your maximum jump length at that position.
//
// Determine if you are able to reach the last index.
//
// Example 1:
//
//
// Input: [2,3,1,1,4]
// Output: true
// Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
//
//
// Example 2:
//
//
// Input: [3,2,1,0,4]
// Output: false
// Explanation: You will always arrive at index 3 no matter what. Its maximum
//              jump length is 0, which makes it impossible to reach the last index.
//
//


class Solution {
public:
    bool canJump(vector<int>& nums) {
        //BFS
        //cout<<endl;
        if(nums.size()<2)return true;
        int check[nums.size()]={0};
        priority_queue<int> open;
        open.push(0);
        int current;
        while(!open.empty()){
            current=open.top();
            //cout<<nums[current]<<" ";
            open.pop();
            for(int i=1;i<=nums[current];i++){
                if(current+i>=nums.size()-1) return true;
                else if(check[current+i]!=1){
                    open.push(current+i);
                    check[current+i]=1;
                }
            }
        }
        //TODO:: dfs
        return false;
    }
};
