// You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].
//
// Example:
//
//
// Input: [5,2,6,1]
// Output: [2,1,1,0] 
// Explanation:
// To the right of 5 there are 2 smaller elements (2 and 1).
// To the right of 2 there is only 1 smaller element (1).
// To the right of 6 there is 1 smaller element (1).
// To the right of 1 there is 0 smaller element.
//


class Solution {
public:
    class FenwickTree{
        public:
        FenwickTree(int n){tree_.resize(n+1);}
        void update(int index, int d){
            while(index<tree_.size()){
                tree_[index]+=d;
                //cout<<"update index:"<<index<<"with curvalue:"<<tree_[index]<<endl;
                index += lowbit_(index);
            }
        }
        
        int query(int index){
            int sum=0;
            while(index>0){
                sum+=tree_[index];
                index-=lowbit_(index);
            }
            return sum;
        }
        
        private:
        inline int lowbit_(int x){
            return x&-x;
        }
        vector<int> tree_;
    };

    
    vector<int> countSmaller(vector<int>& nums) {
        FenwickTree sumTree(nums.size());
        vector<pair<int,int>> set(nums.size()); 
        vector<int> pairindex2order(nums.size());
        vector<int> originindex2orderindex(nums.size());
        vector<int> res(nums.size());
        if(nums.size()==0) return res;
        for(int i=0;i<nums.size();i++){
            set[i]=(make_pair(nums[i],i));
            //cout<<"pair"<<i<<"("<<set[i].second<<","<<set[i].first<<")"<<endl;
        }
      
        
        sort(set.begin(),set.end());
        
        pairindex2order[0]=0;
        originindex2orderindex[set[0].second]=pairindex2order[0];
        for(int i=1;i<set.size();i++){
            if (set[i].first==set[i-1].first){
                pairindex2order[i]=pairindex2order[i-1];
            }
            else{
                pairindex2order[i]=i;
            }
            originindex2orderindex[set[i].second]=pairindex2order[i];
            //cout<<"pair"<<i<<"("<<set[i].first<<","<<set[i].second<<")"<<endl;
        }
        
        for(int i=nums.size()-1;i>=0;i--){
            
            //cout<<"i:"<<pair.second<<"val:"<<pair.first<<endl;
            sumTree.update(originindex2orderindex[i]+1,1);
            res[i]=sumTree.query(originindex2orderindex[i]);
        }
        return res;
    }
};
