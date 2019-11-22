class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        set<string> dict;
        for(int i=0;i<wordDict.size();i++){
            dict.insert(wordDict[i]);
        }
        int n=s.size();
        vector<vector<string> > dp(n,vector<string>(0));
        
        for(int i=n;i>=1;i--){
            for(int j=i-1;j>=0;j--){
                if((i==n||!dp[i].empty())
                   &&dict.find(s.substr(j,i-j))!=dict.end()){
                    dp[j].push_back(s.substr(j,i-j));
                }
            }
        }
        vector<string> res;
        vector<string> cur;
        dfs(0,n,dp,res,cur);
        return res;
    }
    void dfs(int pos,int n,vector<vector<string> >& dp, 
             vector<string>& res,vector<string>& cur){
        if(pos==n){
            string curAns;
            for(int i=0;i<cur.size()-1;i++){
                curAns+=cur[i];
                curAns+=" ";
            }
            curAns+=cur[cur.size()-1];
            res.push_back(curAns);
            return;
        }
        for(int i=0;i<dp[pos].size();i++){
            
            cur.push_back(dp[pos][i]);
            dfs(pos+dp[pos][i].size(),n,dp,res,cur);
            cur.pop_back();
        }
    }
};