class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> ways(m, vector<int>(n, 0));
        ways[0][0] = 1;

        queue<pair<int, int>> grids;
        grids.emplace(0, 0);

        while (!grids.empty()) {
            auto[row, column] = grids.front();
            grids.pop();

            if (!(row == 0 && column == 0) && ways[row][column] != 0) {
                continue;
            }

            if (row - 1 >= 0) {
                ways[row][column] += ways[row -  1][column];
            }
            if (column - 1 >= 0) {
                ways[row][column] += ways[row][column - 1];
            }

            if (row + 1 < m) {
                grids.emplace(row + 1, column);
            }
            if (column + 1 < n) {
                grids.emplace(row, column + 1);
            }
        }
        return ways[m - 1][n - 1];
    }
};
