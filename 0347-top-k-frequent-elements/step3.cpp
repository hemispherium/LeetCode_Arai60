class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequency;
        for (int num : nums) {
            frequency[num]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> kth_largest;
        for (auto& [num, count] : frequency) {
            kth_largest.push({ count, num });
            if (kth_largest.size() > k) {
                kth_largest.pop();
            }
        }
        vector<int> answer;
        while (!kth_largest.empty()) {
            answer.push_back(kth_largest.top().second);
            kth_largest.pop();
        }
        return answer;
    }
};
