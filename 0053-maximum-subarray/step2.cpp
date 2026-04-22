class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> max_values(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) {
                max_values[i] = nums[i];
            } else {
                max_values[i] = max(nums[i], max_values[i - 1] + nums[i]);
            }
        }
        return *max_element(max_values.begin(), max_values.end());
    }
};
