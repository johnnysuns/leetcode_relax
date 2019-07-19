# 30. Substring with Concatenation of All Words

## 简析

在字符串中查找所有子字符串的头索引位置，要求子字符串是一堆字符串元单词不重复不遗漏的组合，元单词长度相同

## 方法：循环减代替整除

1. 首先建立元单词的字典map索引，方便快速查找，val为出现次数；
2. 对每个可能的子字符串进行遍历,每个子字符串建立check_map索引；
3. 对于每个子字符串，根据子字符串的每个子单词，如果字典中存在该单词，check_map对应单词val+1，若对应单词的check_map的val大于字典map的val,则不存在这种组合，每个单词都通过则将子字符串索引加入结果。
4. 
**我的代码：**

```cpp
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
        //check each substring
        for(int i=0;i<s.length()-substring_length+1;i++){
            unordered_map<string,int> check_wordbags;
            for(j=i;j<i+substring_length-length+1;j+=length){
                sub_word=s.substr(j,length);
                val1=wordbags[sub_word];
                if(val1>0){
                    val2=++check_wordbags[sub_word];
                    if(val1<val2) break;
                }else{
                    break;
                }
            }
            if(j==i+substring_length) res.push_back(i);
        }
        return res;
    }
};
```
