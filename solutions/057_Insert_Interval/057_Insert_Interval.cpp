// Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
//
// You may assume that the intervals were initially sorted according to their start times.
//
// Example 1:
//
//
// Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
// Output: [[1,5],[6,9]]
//
//
// Example 2:
//
//
// Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
// Output: [[1,2],[3,10],[12,16]]
// Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
//


/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
  vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
    auto it=equal_range(intervals.begin(),intervals.end(),newInterval,
                        [](const Interval &intA,const Interval &intB){
                            return intA.end<intB.start;
                        }
                       );
      if(it.first==it.second){
        intervals.insert(it.second,newInterval);
      }else{
          it.second--;
          it.second->start=min(newInterval.start, it.first->start);
          it.second->end=max(newInterval.end,it.second->end);
        intervals.erase(it.first, it.second);
      }
    //cout<<"first:"<<it.first->start<<","<<it.first->end<<" second:"<<it.second->start<<","<<it.second->end<<endl;
    return intervals;
  }
};
