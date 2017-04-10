class Solution{
public:
int totalNQueens(int n) {
    vector<bool> col(n, true);
    vector<bool> anti(2*n-1, true);
    vector<bool> main(2*n-1, true);
    vector<int> row(n, 0);
    int count = 0;
    dfs(0, row, col, main, anti, count);
    return count;
}
void dfs(int i, vector<int> &row, vector<bool> &col, vector<bool>& main, vector<bool> &anti, int &count) {
        if (i == row.size()) {
            count++;
            return;
        }
       for (int j = 0; j < col.size(); j++) {
         if (col[j] && main[i+j] && anti[i+col.size()-1-j]) {
             row[i] = j; 
             col[j] = main[i+j] = anti[i+col.size()-1-j] = false;
             dfs(i+1, row, col, main, anti, count);
             col[j] = main[i+j] = anti[i+col.size()-1-j] = true;
      }
    }
}
};

class Solution {
public:
    int totalNQueens(int n) {
        vector<vector<string> > res;
        vector<int> cur;
        Trial(res,cur,0,n);
        return res.size();
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