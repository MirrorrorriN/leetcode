class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int> > res;
        sort(candidates.begin(),candidates.end());
        vector<int> cur;
        dfs(candidates,target,res,cur,0);
        return res;
    }
    void dfs(vector<int>& candidates,int target,vector<vector<int> >& res,vector<int>& cur,int start){
        if(target==0){
            res.push_back(cur);
            return;
        }
        else{
            for(int i=start;i<candidates.size();i++){
                if(candidates[i]>target) return;
                if(i>0&&candidates[i]==candidates[i-1]&&i>start) continue;
                cur.push_back(candidates[i]);
                dfs(candidates,target-candidates[i],res,cur,i+1);
                cur.pop_back();
            }
        }
    }
};