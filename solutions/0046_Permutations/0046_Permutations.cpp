// Given a collection of distinct integers, return all possible permutations.
//
// Example:
//
//
// Input: [1,2,3]
// Output:
// [
//   [1,2,3],
//   [1,3,2],
//   [2,1,3],
//   [2,3,1],
//   [3,1,2],
//   [3,2,1]
// ]
//
//


class Solution {
public:
    void premutationDFS(vector<int>& nums, vector<vector<int>> &res, vector<int>& current_chosen, list<int> &to_be_chosen){
        if(to_be_chosen.size()==0){
            res.emplace_back(current_chosen);
            return;
        }
        
        for(int i=0;i<to_be_chosen.size();i++){
            int index=to_be_chosen.front();
            to_be_chosen.pop_front();
            current_chosen.push_back(nums[index]);
            premutationDFS(nums,res,current_chosen,to_be_chosen);
            current_chosen.pop_back();
            to_be_chosen.push_back(index);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        list<int> tobechoose(nums.size());//index
        vector<int> current_chosen;
        int i=0;
        for(auto it=tobechoose.begin();it!=tobechoose.end();it++){
            *it=i++;
        }
        
        if(nums.size()<=1){
            res.push_back(nums);
        }else{
            premutationDFS(nums,res,current_chosen,tobechoose);
        }
        return res;
    }
};
