class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string> > res;
        vector<int> cur;
        Trial(res,cur,0,n);
        return res;
    }
private:
    bool candidate(vector<int> cur,int newx,int n,int newy){
        for(int i=0;i<cur.size();i++){
            if(newy==cur[i]) return false;
            if(cur[i]-i==newy-newx||cur[i]+i==newy+newx) return false;
        }
        return true;
    }
    void Trial(vector<vector<string> >& res,vector<int> cur,int newx,int n){
        if(newx==n){
            vector<string> sol;         
            for(int i=0;i<n;i++){
                string tmp(n,'.');
                tmp[cur[i]]='Q';
                sol.push_back(tmp);
            }
            res.push_back(sol);
            return;
        }
        for(int i=0;i<n;i++){
            if (candidate(cur,newx,n,i)){
                cur.push_back(i);
                Trial(res,cur,newx+1,n);
                cur.pop_back();
            }
        }
    }
};