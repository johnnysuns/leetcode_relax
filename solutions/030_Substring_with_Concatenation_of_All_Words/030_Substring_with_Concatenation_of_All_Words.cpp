// You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.
//
// Example 1:
//
//
// Input:
//   s = "barfoothefoobarman",
//   words = ["foo","bar"]
// Output: [0,9]
// Explanation: Substrings starting at index 0 and 9 are "barfoor" and "foobar" respectively.
// The output order does not matter, returning [9,0] is fine too.
//
//
// Example 2:
//
//
// Input:
//   s = "wordgoodstudentgoodword",
//   words = ["word","student"]
// Output: []
//
//


class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if(words.size()==0) return res;
        int length=words[0].length();
        int substring_length=length*words.size();
        if(s.length()<substring_length) return res;
        unordered_map<string,int> wordbags;
        string sub_word;
        int val1,val2;
        //build wordbags index
        for(int i=0;i<words.size();i++){
            wordbags[words[i]]++;
        }
        int j;
        for(int i=0;i<s.length()-substring_length+1;i++){
            unordered_map<string,int> check_wordbags;
            for(j=i;j<i+substring_length-length+1;j+=length){
                //cout<<"i:"<<i<<" j:"<<j<<endl;
                sub_word=s.substr(j,length);
                val1=wordbags[sub_word];
                if(val1>0){
                    val2=++check_wordbags[sub_word];
                    if(val1<val2) break;
                }else{
                    break;
                }
            }
            //cout<<"i:"<<i<<" j:"<<j<<endl;
            if(j==i+substring_length) res.push_back(i);
        }
        return res;
    }
};
