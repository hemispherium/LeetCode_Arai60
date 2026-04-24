class Solution {
public:
    int RobRange(const vector<int>& nums, int l, int r) {
        int prev2 = 0;
        int prev1 = 0;

        for (int i = l; i <= r; i++) {
            int current = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }

    int rob(vector<int>& nums) {
        int size = nums.size();

        if (size == 1) {
            return nums[0];
        }

        return max(
            RobRange(nums, 0, size - 2),
            RobRange(nums, 1, size - 1)
        );
    }
};
