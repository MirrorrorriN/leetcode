class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cur=0,res=0;
        if (prices.size()==0) return 0;
        for(int i=0;i<prices.size()-1;i++){
            cur=max(cur+=(prices[i+1]-prices[i]),0);
            res=max(cur,res);
        }
        return res;
    }
};