# 304. Find First and Last Position of Element in Sorted Array    

## 简析

有序数组中查找target的边界位置，不存在返回[-1,-1]

## 方法：二分查找

STL大法好！

**我的代码：**

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto ij=equal_range(nums.begin(),nums.end(),target);
        if(ij.first!=ij.second){
            return vector<int>{ij.first-nums.begin(),ij.second-nums.begin()-1};
        }else{
            return vector<int>{-1,-1};
        }
    }
};
```
