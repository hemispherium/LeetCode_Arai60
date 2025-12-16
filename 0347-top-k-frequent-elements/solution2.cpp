class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> num_to_count;

        for (int num : nums) {
            num_to_count[num]++;
        }

        priority_queue<pair<int, int>> largest;
        for (auto& [num, count] : num_to_count) {
            largest.push({count, num});
        }

        vector<int> answer;
        for (int i = 0; i < k; i++) {
            answer.push_back(largest.top().second);
            largest.pop();
        }

        return answer;
    }
};
