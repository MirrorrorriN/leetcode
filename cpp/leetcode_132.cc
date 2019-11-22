#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int minCut(string s) {
        this->res=INT_MAX;
        vector<vector<bool> > is_palin=this->build2DPalin(s);
        unordered_map<int, unordered_map<int,int> > dp;
        return dfs(s,0,s.length()-1,is_palin,dp);
    }
private:
    int res;
    vector<vector<bool> > build2DPalin(string & s) {
        vector<vector<bool> > is_palin(s.size(), vector<bool>(s.size(), false));
        for (int i = 0; i < s.size(); i++) {
            if (i+1 < s.size() && s[i] == s[i+1]) {
                is_palin[i][i+1] = true;
            }
            is_palin[i][i] = true;
        }
        
        for (int i = s.size()-3; i >= 0; i--) {
            for (int j = i+1; j < s.size(); j++) {
                if (s[i] == s[j] && is_palin[i+1][j-1]) {
                    is_palin[i][j] = true;
                }
            }
        }
        return is_palin;
    }  

    int dfs(string &s, int i,int j,vector<vector<bool> >& is_palin,unordered_map<int,unordered_map<int,int> >& dp) {
        if(dp.find(i)!=dp.end()&&dp[i].find(j)!=dp[i].end()){
            return dp[i][j];
        }
        if(is_palin[i][j]){
            dp[i][j]=0;
            return 0;
        }
        int res=INT_MAX;
        for(int k=i;k<j;k++){
            if(is_palin[i][k]){
                res=min(res,dfs(s,k+1,j,is_palin,dp)+1);
            }
            if(res==1) break;
        }
        dp[i][j]=res;
        return res;
    }

};