class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>> sum(size, vector<int>(2));
        for (int i = 0; i < size; i++) {
            if (i == 0) {
                sum[i][0] = 0;
                sum[i][1] = nums[i];
            } else if (i == 1) {
                sum[i][0] = max(nums[i], sum[i - 1][0]);
                sum[i][1] = max(nums[i], sum[i - 1][1]);
            } else if (i == size - 1) {
                sum[i][0] = max(sum[i - 1][0], sum[i - 2][0] + nums[i]);
                sum[i][1] = max(sum[i - 1][1], sum[i - 2][1]);
            } else {
                sum[i][0] = max(sum[i - 1][0], sum[i - 2][0] + nums[i]);
                sum[i][1] = max(sum[i - 1][1], sum[i - 2][1] + nums[i]);
            }
        }
        return max(sum[size - 1][0], sum[size - 1][1]);
    }
};
