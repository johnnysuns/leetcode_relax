// Given an array of strings, group anagrams together.
//
// Example:
//
//
// Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
// Output:
// [
//   ["ate","eat","tea"],
//   ["nat","tan"],
//   ["bat"]
// ]
//
// Note:
//
//
// 	All inputs will be in lowercase.
// 	The order of your output does not matter.
//
//


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,int> exist;
        vector<vector<string>> res;
        int typeCount=0;
        for(int i=0;i<strs.size();i++){
            string str=strs[i];
            sort(str.begin(),str.end());
            if(exist[str]==0){
                exist[str]=++typeCount;
                vector<string> new_type;
                new_type.emplace_back(strs[i]);
                res.emplace_back(new_type);
            }
            else{
                res[exist[str]-1].emplace_back(strs[i]);
            }
        }
        
        return res;
    }
};
