class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > res;
        vector<int> comb;
        findSum(res, candidates, target, 0, comb);
        return res;
    }
    void findSum(vector<vector<int> >& res, vector<int>& candidates, int target,int start,vector<int>& comb) {
        if (!target) {
            res.push_back(comb);
            return;
        }
        for (int i = start; i < candidates.size()&&target>=candidates[i]; i++) {
            comb.push_back(candidates[i]);
            findSum(res, candidates, target - candidates[i], i, comb);
            comb.pop_back();
        }
    }
};