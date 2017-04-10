class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > res{};
        if (0==numRows) return res;
        res.push_back({1});
        if (1==numRows) return res;
        res.push_back({1,1});
        if (2==numRows) return res;
        vector<int> old={1,1};
        for(int i=2;i<numRows;i++){
            vector<int> cur(i+1,1);
            for(int j=1;j<i;j++){
                cur[j]=old[j-1]+old[j];
            }
            old=cur;
            res.push_back(cur);
        }
        return res;
    }
};