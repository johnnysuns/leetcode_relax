# 39. Combination Sum

## 简析

不重复候选正数，选出所有集合内数的和等于目标和的集合。

## 方法：DFS/回溯（backtracking）

维护一个当前选中数的数组和当前和。

由于要避免重复，因此首先将数组排序，下一个数总是大于等于前一个数，以此保证有序与集合唯一。

从集合中遍历候选数
- 若当前和加上这个数
    - 小于目标，则继续遍历**从该数开始的**候选数（递归）
    - 若当前和加上这个数等于目标，存入选中数组
- 每次遍历完从当前选中数组中删除该数 

**我的代码：**

```cpp
class Solution {
public:
    void search(vector<vector<int>> &res, vector<int> &candidates, vector<int> &current_choosen,int i, int &sum, int target){
        int cur_sum=candidates[i]+sum;
        while(i<candidates.size() && cur_sum<=target){
            current_choosen.push_back(candidates[i]);
            if(cur_sum < target){
                search(res, candidates, current_choosen, i, cur_sum, target);
            }else{
                res.emplace_back(current_choosen);
            }
            i++;
            cur_sum=candidates[i]+sum;
            current_choosen.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> current_choosen;
        int sum=0;
        if(candidates.size()==0) return res;
        sort(candidates.begin(),candidates.end());
        search(res, candidates, current_choosen, 0, sum, target);
        return res;
    }
};
```
