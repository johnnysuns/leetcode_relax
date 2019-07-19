// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//
// (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
//
// You are given a target value to search. If found in the array return its index, otherwise return -1.
//
// You may assume no duplicate exists in the array.
//
// Your algorithm's runtime complexity must be in the order of O(log n).
//
// Example 1:
//
//
// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4
//
//
// Example 2:
//
//
// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1
//


class Solution {
public:
    int search(vector<int>& nums, int target,int l,int r) {
        int mid_i =(r+l)/2;
        int mid_v =nums[mid_i];
        //cout<<"searching l="<<l<<" r="<<r<<endl;
        if(mid_v==target){
            return mid_i;
        }else {
            if(l<r){
                if(nums[r]>nums[l]){ //normal
                    if(mid_v>target) return search(nums, target,l,mid_i);
                    else return search(nums, target,mid_i+1,r);
                }else{//pivot
                    if(nums[l]<=mid_v){//normal left
                        if(mid_v>target){
                            if(target>nums[r]) return search(nums, target,l,mid_i);
                            else return search(nums, target,mid_i+1,r);
                        }else{
                            return search(nums, target,mid_i+1,r);
                        }
                    }
                    else{//normal right
                        if(mid_v>target){
                            return search(nums, target,l,mid_i);                        
                        }else{
                            if(target>nums[r])return search(nums, target,l,mid_i);
                            else return search(nums, target,mid_i+1,r);
                        }
                    }
                }
            }else{
                return -1;
            }
        }
    }
    int search(vector<int>& nums, int target) {
        if (nums.size()==0)return -1;
        return search(nums, target,0,nums.size()-1);
    }
};
