class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res=0;
        for(size_t i=1;i<prices.size();i++)
            res+=max(prices[i]-prices[i-1],0);
        return res;
    }
};