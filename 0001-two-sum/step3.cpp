class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> value_index;
        for (int i = 0; i < nums.size(); i++) {
            int another = target - nums[i];
            if (value_index.count(another)) {
                return { value_index[another], i };
            }
            value_index[nums[i]] = i;
        }
        return {};
    }
};