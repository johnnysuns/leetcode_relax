// Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.
//
// The same repeated number may be chosen from candidates unlimited number of times.
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
// Input: candidates = [2,3,6,7], target = 7,
// A solution set is:
// [
//   [7],
//   [2,2,3]
// ]
//
//
// Example 2:
//
//
// Input: candidates = [2,3,5], target = 8,
// A solution set is:
// [
//   [2,2,2,2],
//   [2,3,3],
//   [3,5]
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

