/**
 * Definition for an interval.
  */
struct Interval
{
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
  int eraseOverlapIntervals(vector<Interval>& intervals)
  {

  }
};

int main(int argc,char** argv)
{
	vector<Interval> intervals{Interval(1,2),Interval(1,2)};
	Solution* x=new Solution();
  cout<<x->eraseOverlapIntervals(intervals);
  return 0;
}

