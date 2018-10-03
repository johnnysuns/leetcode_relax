# 018 4Sum

这道题类似015 3sum和016 3sum，区别在于多了一个加数，所以需要多一层循环。

另外，本题的测试数据也相较前两题有更多解，需要充分考虑重复的情况。

## 方法一：暴力枚举

顾名思义用四层循环检查每组数，结果无序，不利于查重

## 方法二：map映射

类似我在015中的做法，将数组中的数用map映射起来，通过前三个数值计算出最后一个数，利用map查找改数存不存在。

利用map结构，统计所有数字元素的个数，key为数字，val为出现次数。能同时起到排序和去重的作用,相对于桶排对于大间隔数据能节约很多内存空间。

但是在一些情况下可能比方法三中直接遍历数组要低效。如果不要求结果顺序，unsorted_map可能更快。

## 方法三：

本方法最初是源于在015的讨论中看到的方法。
假设a+b+c+d=target

 1. 对数组排序；
 2. 第一层循环固定第一个数a；
    - 不与上一个a相同；
 3. 第二层循环固定第二个数b；
    - 不与上一个b相同；
 4. 在b与末尾设定两个数的索引l，r，并向中间逼近；
    - 结果大了缩小r，结果小了增大l，结果相等记录输出并减小r（或同时增加l）
    - 保证r，l不与上一个值相同

我的代码：

```cpp
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
```
