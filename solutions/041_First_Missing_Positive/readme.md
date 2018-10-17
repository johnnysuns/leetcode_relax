# 41. First Missing Positive

## 简析

从数组中找出缺失的最小正数。时间要求O(n),因此不能排序。

- 最小正数从1开始，因此忽略负数。
- 若数组长度为n，则最小正数必定出现在[1, n+1]内

十行代码即可，这道题配不上hard的称号。。

## 方法：

可以建立n+1长度的查询数组，用来快速查找某数是否存在。遍历给定数组，填充查询数组，若最小数存在则递增最小数。


**我的代码：**

```cpp
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int exist[nums.size()+2]={0};
        int min=1;
        for(int i=0;i<nums.size();i++){
            if((nums[i]>=min)&&(nums[i]<=nums.size())){
                exist[nums[i]]=1;
                while(exist[min]) min++;
            }
        }
        return min;
    }
};
```
