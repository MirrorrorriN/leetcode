/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool cmp(Interval a,Interval b){
        if(a.start!=b.start) return (a.start<b.start);
        return (a.end<b.end);
}
class Solution {
public:
    
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        for(int i=1;i<intervals.size();i++){
            if (intervals[i].start<=intervals[i-1].end){
                intervals[i-1].end=max(intervals[i-1].end,intervals[i].end);
                intervals.erase(intervals.begin()+i);
                i--;
                
            }
            else continue;
        }
        return intervals;
    }
    
};

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
    
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(),intervals.end(),[](Interval a,Interval b){return a.start<b.start;});
        vector<Interval> res={};
        if (intervals.empty()) return res;
        res.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            if (res.back().end<intervals[i].start) res.push_back(intervals[i]);
            else res.back().end=max(res.back().end,intervals[i].end);
        }
        return res;
    }
    
};
