class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, vector<int>> map;
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]].push_back(i);
        }
        vector<int> retVal;
        for (auto it = map.begin(); it != map.end(); it++) {
            int x = it->first;
            if (2 * x == target && it->second.size() >= 2) {
                retVal.push_back(it->second[0]);
                retVal.push_back(it->second[1]);
                return retVal;
            } else if (2 * x != target) {
                auto it2 = map.find(target - x);
                if (it2 != map.end()) {
                    retVal.push_back(it->second[0]);
                    retVal.push_back(it2->second[0]);
                    return retVal;
                }
            }
        }
        return {};
    }
};