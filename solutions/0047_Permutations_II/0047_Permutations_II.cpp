// Given a collection of numbers that might contain duplicates, return all possible unique permutations.
//
// Example:
//
//
// Input: [1,1,2]
// Output:
// [
//   [1,1,2],
//   [1,2,1],
//   [2,1,1]
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
        unordered_map<int,int> exist;
        for(int i=0;i<to_be_chosen.size();i++){
            int index=to_be_chosen.front();
            to_be_chosen.pop_front();
            if(exist[nums[index]]==0){
                exist[nums[index]]=1;
                current_chosen.push_back(nums[index]);
                premutationDFS(nums,res,current_chosen,to_be_chosen);
                current_chosen.pop_back();
            }
            to_be_chosen.push_back(index);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
    
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
