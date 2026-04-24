class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
        int column = obstacleGrid[0].size();

        vector<int> ways(column, 0);

        ways[0] = (obstacleGrid[0][0] == 0) ? 1 : 0;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                if (obstacleGrid[i][j] == 1) {
                    ways[j] = 0;
                } else if (j > 0) {
                    ways[j] += ways[j - 1];
                }
            }
        }

        return ways[column - 1];
    }
};
