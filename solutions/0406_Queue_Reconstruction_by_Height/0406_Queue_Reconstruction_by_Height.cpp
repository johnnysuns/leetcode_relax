// Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.
//
// Note:
// The number of people is less than 1,100.
//  
//
// Example
//
//
// Input:
// [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
//
// Output:
// [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
//
//
//  
//


class Solution {
public:
    map<int,int> stat;
    int get_people_higher_n(int h){
        int res=0;
        auto it = stat.lower_bound(h);
        while(it!=stat.end()){
            res+=it->second;
            it++;
        }
        return res;
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end());
        vector<vector<int>> res;
        int n=0;
         // for(int i=0;i<people.size();i++){
         // cout<<" ["<<people[i][0]<<","<<people[i][1]<<"] ";
         // }
        //cout<<endl;
        int people_size=people.size();
        while(n<people_size){
            for(int i=0;i<people.size();i++){
                //cout<< "i:"<<i<<endl;
                if(people[i][1]<=n && people[i][1]==get_people_higher_n(people[i][0])){
                    //find next person
                    res.push_back(people[i]);
                    people.erase(people.begin()+i);
                    i--;
                    //swap(people[n],people[i]);
                    stat[res[n][0]]++;
                    //cout<<" n:"<<n<<" "<<res[n][0];
                    n++;
                     // for(int ii=0;ii<people.size();ii++){
                     // cout<<" ["<<people[ii][0]<<","<<people[ii][1]<<"] " ;
                     // }
                    break;
                }
            }
        } 
        return res;
    }
};
