// Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
//
// Note:
//
// The solution set must not contain duplicate triplets.
//
// Example:
//
//
// Given array nums = [-1, 0, 1, 2, -1, -4],
//
// A solution set is:
// [
//   [-1, 0, 1],
//   [-1, -1, 2]
// ]
//
//


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        map<int, int> num_map;
        vector<vector<int>> ret;
        vector<int> res;
        map<int,int>::iterator itc;
        map<int,int>::iterator ita;
        map<int,int>::iterator itb;
        int t;
        int exist;
        //Construct index map
        for(int i=0;i<nums.size();i++){
            itc=num_map.find(nums[i]);
            if(itc==num_map.end()) num_map.insert(pair<int,int>(nums[i],1));
            else itc->second++;
        }
        
        int c,a,b;//a+b=c,c=-element in map -c<a<b

        for(itc=num_map.begin();itc!=num_map.end();itc++)
        {
            c=-itc->first;
            itc->second--;
            for(ita=itc;ita!=num_map.end();ita++)
            {
                a=ita->first;
                if(ita->second>0) ita->second--;
                else continue;
                //check a+b=c
                b=c-a;
                if((b>=a))
                {
                    itb=num_map.find(b);
                    if(itb!=num_map.end()&&(itb->second>0)){//find equation
                        res.clear();
                        res.push_back(-c);
                        res.push_back(a);
                        res.push_back(b);
                        ret.push_back(res);
//                         if(res[0]>res[1]){
//                             t=res[0];
//                             res[0]=res[1];
//                             res[1]=t;
//                         }
//                         if(res[1]>res[2]){
//                             t=res[1];
//                             res[1]=res[2];
//                             res[2]=t;
//                         }
//                         if(res[0]>res[1]){
//                             t=res[0];
//                             res[0]=res[1];
//                             res[1]=t;
//                         }
//                         //check unique
//                         exist=0;
//                         if(ret.size()){
//                             for(int i=0;i<ret.size();i++){
//                                 if(ret[i][0]==res[0]&&ret[i][1]==res[1]&&ret[i][2]==res[2]){
//                                     exist=1;
//                                     break;
//                                 }
//                             }

//                         }
//                         if(exist==0)ret.push_back(res);
                    }
                }
                ita->second++;
                    
            }
            itc->second++;
        }
        return ret;
    }
};
