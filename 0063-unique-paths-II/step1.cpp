class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
        int column = obstacleGrid[0].size();
        if (row == 1 && column == 1 && obstacleGrid[row - 1][column - 1]) {
            return 0;
        }
        vector<vector<int>> ways(row, vector<int>(column));
        ways[0][0] = 1;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }
                if (obstacleGrid[i][j]) {
                    continue;
                }
                if (i - 1 >= 0 && !obstacleGrid[i - 1][j]) {
                    ways[i][j] += ways[i - 1][j];
                }
                if (j - 1 >= 0 && !obstacleGrid[i][j - 1]) {
                    ways[i][j] += ways[i][j - 1];
                }
            }
        }
        return ways[row - 1][column - 1];
    }
};
