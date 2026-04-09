class Solution {
public:
    int m, n;

    void f(vector<vector<int>>& grid, int x, int y, int& val) {
        if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 0) {
            return;
        }
        grid[x][y] = 0;
        val++;
        f(grid, x + 1, y, val);
        f(grid, x - 1, y, val);
        f(grid, x, y + 1, val);
        f(grid, x, y - 1, val);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int maxArea = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int val = 0;
                    f(grid, i, j, val);
                    maxArea = max(maxArea, val);
                }
            }
        }
        return maxArea;
    }
};
