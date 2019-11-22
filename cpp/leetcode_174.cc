#include<vector>
#include<iostream>
using namespace std;
//正序有一种特殊case不知应如何处理？
class Solution {
public:
    int calculateMinimumHP(vector<vector<int> >& dungeon) {
        if(dungeon.size()==0){
            return 1;
        }
        int M=dungeon.size();
        int N=dungeon[0].size();
        vector<vector<pair<int,int> > > dp(M,vector<pair<int,int> >(N,make_pair(0,0)));
        dp[0][0]=make_pair(min(0,dungeon[0][0]),dungeon[0][0]);
        for(int i=1;i<M;i++){
            dp[i][0].first=min(dp[i-1][0].first,dp[i-1][0].second+dungeon[i][0]);
            dp[i][0].second=dp[i-1][0].second+dungeon[i][0];
        }
        for(int i=1;i<N;i++){
            dp[0][i].first=min(dp[0][i-1].first,dp[0][i-1].second+dungeon[0][i]);
            dp[0][i].second=dp[0][i-1].second+dungeon[0][i];
        }
        for(int i=1;i<M;i++){
            for(int j=1;j<N;j++){
                if(dp[i-1][j].first>dp[i][j-1].first){
                    dp[i][j].second=dp[i-1][j].second+dungeon[i][j];
                }else if(dp[i-1][j].first<dp[i][j-1].first){
                    dp[i][j].second=dp[i][j-1].second+dungeon[i][j];
                }else{
                    dp[i][j].second=max(dp[i-1][j].second,dp[i][j-1].second)+dungeon[i][j];
                }
                dp[i][j].first=min(max(dp[i-1][j].first,dp[i-1][j].first),
                                      dp[i][j].second);
            }
        }
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                cout<<"|";
                cout<<dp[i][j].first<<","<<dp[i][j].second;
                cout<<"|";
            }
            cout<<endl;
        }
        return -dp[M-1][N-1].first+1;
    }
};

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
        dp[m][n - 1] = 1; dp[m - 1][n] = 1;
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                dp[i][j] = max(1, min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j]);
            }
        }
        return dp[0][0];
    }
};