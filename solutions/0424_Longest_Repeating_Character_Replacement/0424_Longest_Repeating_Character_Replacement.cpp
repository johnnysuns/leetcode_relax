// Given a string s that consists of only uppercase English letters, you can perform at most k operations on that string.
//
// In one operation, you can choose any character of the string and change it to any other uppercase English character.
//
// Find the length of the longest sub-string containing all repeating letters you can get after performing the above operations.
//
// Note:
// Both the string's length and k will not exceed 104.
//
// Example 1:
//
//
// Input:
// s = "ABAB", k = 2
//
// Output:
// 4
//
// Explanation:
// Replace the two 'A's with two 'B's or vice versa.
//
//
//  
//
// Example 2:
//
//
// Input:
// s = "AABABBA", k = 1
//
// Output:
// 4
//
// Explanation:
// Replace the one 'A' in the middle with 'B' and form "AABBBBA".
// The substring "BBBB" has the longest repeating letters, which is 4.
//
//
//  
//


class Solution {
public:
    //TLE
    // int chr(string &s, char ch, int ch_index,int k,bool isnewlen){
    //     if(k<0) return -1;
    //     if(ch_index>s.length()-1)return 0;
    //     int len=0;
    //     //cout<<"isnewlen " <<isnewlen<<"ch_index"<<ch_index<<"k:"<<k<<endl;
    //     while(ch_index<s.length()){
    //         if(s[ch_index]!=ch){
    //             int len_old=len+1+chr(s,ch, ch_index+1,k-1,0);
    //             if(isnewlen){
    //                 int len_new=chr(s,s[ch_index], ch_index,k,1);
    //                 if(ch_index>0)
    //                     len_new=max(len_new,1+chr(s,s[ch_index], ch_index,k-1,1));
    //                 return max(len_old,len_new);   
    //             }else{
    //                 return len_old;
    //             }
    //         }else{
    //             len++;
    //             ch_index++;
    //         }
    //     }
    //     return len;
    // }
    // int characterReplacement(string s, int k) {
    //     if(s=="")return 0;
    //     return chr(s,s[0],0,k,1);
    // }
    //using sliding window
    int characterReplacement(string s, int k) {
        int counter[27]={0};
        int max_len=0;
        int max_count=0;
        int start=0;
        for(int end=1;end<=s.length();end++){
            max_count=max(max_count,++counter[s[end-1]-'A']);
            while(end-start-max_count>k){
                --counter[s[start]-'A'];
                start++;
            }
        }
        return s.length()-start;
    }
};
