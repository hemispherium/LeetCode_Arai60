class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        map<int, int> val_and_length;

        int max_length = 1;
        for (int i = 0; i < nums.size(); i++) {
            val_and_length[nums[i]] = max(1, val_and_length[nums[i]]);
            for (auto it = val_and_length.begin(); it != val_and_length.end(); it++) {
                auto [val, length] = *it;
                if (nums[i] > val) {
                    val_and_length[nums[i]] = max(length + 1, val_and_length[nums[i]]);
                    max_length = max(max_length, val_and_length[nums[i]]);
                }
            }
        }
        return max_length;
    }
};
