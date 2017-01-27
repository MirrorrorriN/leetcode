#include <vector>
#include <iostream>
#include <limits.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        int n=nums.size();
        int res=INT_MIN;
        int weight=0;
        for (int i=0;i<n;i++)
        {
              res=max(res,weight+nums[i]);
              weight=max(weight+nums[i],0);
        }
        return res;
    }
};

int main(int argc,char** argv)
{
        Solution* x=new Solution();
        vector<int> prices{-2,-1};
        cout<<x->maxSubArray(prices)<<endl;
        return 0;
}
