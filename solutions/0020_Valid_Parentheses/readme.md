# 20. Valid Parentheses

## 简析

    括号匹配，如果是单括号可以统计左右个数。这里涉及到多个括号，使用栈来进行配对

## 方法：

检查下一个括号

- 左括号则入栈
- 右括号则检查栈，若**栈非空**且**栈顶括号为匹配的左括号**则配对成功弹出栈顶元素，~~两括号私奔~~，否则不合法；

## 我的代码：

```cpp
class Solution {
public:
    bool isValid(string s) {
        stack<char> stackBoom;
        for(int i=0;i<s.length();i++){
            switch(s[i]){
                case '(':
                case '[':
                case '{':
                    stackBoom.push(s[i]);
                    break;
                case ')':
                    if(!stackBoom.empty()&&(stackBoom.top()=='(')) stackBoom.pop();
                    else return false;
                    break;
                case ']':
                    if(!stackBoom.empty()&&(stackBoom.top()=='[')) stackBoom.pop();
                    else return false;
                    break;
                case '}':
                    if(!stackBoom.empty()&&(stackBoom.top()=='{')) stackBoom.pop();
                    else return false;
                    break;
                default:
                    return false;
                    break;
            }
        }
        if(stackBoom.empty()) return true;
        else return false;
    }
};
```
