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