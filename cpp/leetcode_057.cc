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
        if (intervals.empty()){
            intervals.push_back(newInterval);
            return intervals;
        }
        auto it=intervals.begin();
        while(it!=intervals.end()&&it->end<newInterval.start){
            it++;
        }
        auto s=it;
        if(it==intervals.end()){
            intervals.push_back(newInterval);
            return intervals;
        }
        while(it!=intervals.end()&&it->start<=newInterval.end){
            it++;
        }
        auto e=it-1;
        Interval tmp(min(s->start,newInterval.start),max(e->end,newInterval.end));
        intervals.erase(s,e+1);
        intervals.insert(s,tmp);
        return intervals;
    }
};