class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> smallest;
        for (int i = 0; i < nums2.size(); i++) {
            smallest.push({nums1[0] + nums2[i], {0, i}});
        }
        vector<vector<int>> answer;
        while (!smallest.empty() && answer.size() < k) {
            auto [sum, nums] = smallest.top();
            smallest.pop();
            int num1 = nums.first;
            int num2 = nums.second;
            answer.push_back({nums1[num1], nums2[num2]});
            if (num1 + 1 < nums1.size()) {
                smallest.push({nums1[num1 + 1] + nums2[num2], {num1 + 1, num2}});
            }
        }
        return answer;
    }
};
