class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if (m == 0) return 0;
        int n = obstacleGrid[0].size();
        vector<int> path(n + 1, 0);
        int k = 1;
        while (k<=n && obstacleGrid[0][k - 1] == 0) {
            path[k] = 1;
            k++;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j <= n; j++) {
                if (obstacleGrid[i][j-1] == 1) path[j] = 0;
                else path[j] = path[j-1] + path[j];
            }
        }
        return path[n];
    }
};