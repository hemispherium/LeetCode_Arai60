class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, vector<int>> num_index;
        for (int i = 0; i < nums.size(); i++) {
            num_index[nums[i]].push_back(i);
        }
        vector<int> retVal;
        for (auto it = num_index.begin(); it != num_index.end(); it++) {
            int first_num = it->first;
            if (2 * first_num == target && it->second.size() >= 2) {
                retVal.push_back(it->second[0]);
                retVal.push_back(it->second[1]);
                return retVal;
            } else if (2 * first_num != target) {
                auto it2 = num_index.find(target - first_num);
                if (it2 != num_index.end()) {
                    retVal.push_back(it->second[0]);
                    retVal.push_back(it2->second[0]);
                    return retVal;
                }
            }
        }
        return {};
    }
};