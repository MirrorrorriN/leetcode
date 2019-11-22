#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.empty()){
            return 0;
        }
        //k>=prices.size()/2时 相当于无次数限制，可进一步降维
        if(k>=prices.size()/2){
            vector<int> dp(2,0);
            dp[1]=-prices[0];
            for(int i=1;i<prices.size();i++){
                dp[0]=max(dp[0],dp[1]+prices[i]);
                dp[1]=max(dp[1],dp[0]-prices[i]);
            }
            return dp[0];
        }
        vector<vector<int> > dp(k+1,vector<int>(2,0));
        for(int i=0;i<=k;i++){
            dp[i][0]=0;
            dp[i][1]=-prices[0];
        }
        for(int i=1;i<prices.size();i++){
            for(int j=1;j<=k;j++){
                dp[j][1]=max(dp[j][1],dp[j-1][0]-prices[i]);
                dp[j][0]=max(dp[j][0],dp[j][1]+prices[i]);
            }
        }
        return dp[k][0];
    }
};