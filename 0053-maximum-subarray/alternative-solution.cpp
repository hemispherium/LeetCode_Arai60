class Solution {
public:
    int helper(vector<int>& nums, int left, int right) {
        if (left == right) {
            return nums[left];
        }

        int mid = (left + right) / 2;

        int leftMax = helper(nums, left, mid);
        int rightMax = helper(nums, mid + 1, right);

        int leftSum = numeric_limits<int>::min();
        int sum = 0;
        for (int i = mid; i >= left; i--) {
            sum += nums[i];
            leftSum = max(leftSum, sum);
        }

        int rightSum = numeric_limits<int>::min();
        sum = 0;
        for (int i = mid + 1; i <= right; i++) {
            sum += nums[i];
            rightSum = max(rightSum, sum);
        }

        int crossMax = leftSum + rightSum;

        return max({leftMax, rightMax, crossMax});
    }

    int maxSubArray(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
};
