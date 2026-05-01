class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        auto it = find(nums.begin(), nums.end(), target);
        if (it != nums.end()) {
            return it - nums.begin();
        }
        auto it2 = lower_bound(nums.begin(), nums.end(), target);
        if (it2 != nums.end()) {
            return it2 - nums.begin();
        }
        return nums.size();
    }
};
