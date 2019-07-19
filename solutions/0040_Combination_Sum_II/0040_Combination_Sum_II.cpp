// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.
//
// Each number in candidates may only be used once in the combination.
//
// Note:
//
//
// 	All numbers (including target) will be positive integers.
// 	The solution set must not contain duplicate combinations.
//
//
// Example 1:
//
//
// Input: candidates = [10,1,2,7,6,1,5], target = 8,
// A solution set is:
// [
//   [1, 7],
//   [1, 2, 5],
//   [2, 6],
//   [1, 1, 6]
// ]
//
//
// Example 2:
//
//
// Input: candidates = [2,5,2,1,2], target = 5,
// A solution set is:
// [
//   [1,2,2],
//   [5]
// ]
//
//


class Solution {
public:
    void search(vector<vector<int>> &res, vector<int> &candidates, vector<int> &current_choosen,int i, int &sum, int target){
        int cur_sum=candidates[i]+sum;
        while(i<candidates.size() && cur_sum<=target){
            current_choosen.push_back(candidates[i]);
            if(cur_sum < target){
                search(res, candidates, current_choosen, i+1, cur_sum, target);
            }else{
                res.emplace_back(current_choosen);
            }
            while(++i<candidates.size() && candidates[i]==candidates[i-1]);
            cur_sum=candidates[i]+sum;
            current_choosen.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> current_choosen;
        int sum=0;
        if(candidates.size()==0) return res;
        sort(candidates.begin(),candidates.end());
        search(res, candidates, current_choosen, 0, sum, target);
        return res;
    }
};
