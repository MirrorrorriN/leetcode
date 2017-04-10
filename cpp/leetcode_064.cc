class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 0) return 0;
        int n = grid[0].size();
        vector<int> res(n + 1, INT_MAX);
        for (int i = 1; i <= n; i++) {
            res[i] = grid[0][i - 1] +( i == 1 ? 0 : res[i-1]);
        }
        for (int i = 1; i<grid.size(); i++) {
            for (int j = 1; j <= n; j++) {
                res[j] = min(res[j - 1], res[j]) + grid[i][j - 1];
            }
        }
        return res[n];
    }
};