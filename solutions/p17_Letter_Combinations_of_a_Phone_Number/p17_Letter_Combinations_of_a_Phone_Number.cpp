class Solution {
public:

    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.length()==0) return {};
        res.reserve(pow(4,digits.length()));
        res.push_back("");
        vector<vector<string>> s={
            {" "},//0
            {"*"},//1
            {"a","b","c"},
            {"d","e","f"},
            {"g","h","i"},
            {"j","k","l"},
            {"m","n","o"},
            {"p","q","r","s"},
            {"t","u","v"},
            {"w","x","y","z"}
        };
        int index;
        for(int i=digits.length()-1;i>-1;i--){
            index=digits[i]-'0';
            int cur_len=res.size();
            for(int j=1;j<s[index].size();j++){
                for(int k=0;k<cur_len;k++){
                    res.push_back(s[index][j]+res[k]);
                }
            }
            for(int k=0;k<cur_len;k++){
                res[k]=(s[index][0]+res[k]);
            }
        }
        return res;
    }
};