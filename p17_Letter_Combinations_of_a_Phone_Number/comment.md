# 方法一：递归

在submission中发现有同学使用递归的方法，程序比较简单。
但是每一次计算printwords都会重复计算子字符串，非常耗时。

```cpp
void printwords(vector<string>*p,unordered_map<int,string> *mp,string &digits, int start, int size,string word)
{
    if (start==size)
    {
        (*p).push_back(word);
    }
    else
    {
        int dig=digits[start]-'0';
        int l=(*mp)[dig].size();
        for(int i =0;i<l;i++)
        {
            string word2=word+(*mp)[dig][i];
            cout<<word2<<endl;
            printwords(p,mp,digits,start+1,size,word2);
        }
    }
}
```

# 方法二：递推

递推的方法相比于递归速度更快，因为不需要重复计算。
方法为从后往前遍历digits每个元素，每考虑一个元素，将res复制digits[i]数字对应字母数倍，分别在新res中的每份旧res前面加上digits[i]中各字母。

经过测试，发现官方例程中将0和1也作为字符串考虑进来，这里也这么做。

**坑爹的是**，测试中，digits输入""时官方例程输出为[]（空vector），如果你的程序输出是[""]（vector里有一个空字符串）将会被判别为WA

我的源码
```cpp
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
```