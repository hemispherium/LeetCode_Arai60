class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> length_and_val;

        for (int x : nums) {
            auto it = lower_bound(length_and_val.begin(), length_and_val.end(), x);

            if (it == length_and_val.end()) {
                length_and_val.push_back(x);
            } else {
                *it = x;
            }
        }

        return length_and_val.size();
    }
};
