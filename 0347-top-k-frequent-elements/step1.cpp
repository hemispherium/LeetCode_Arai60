class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequency_to_idx;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> kth_largest;
        for (int num : nums) frequency_to_idx[num]++;
        for (auto it = frequency_to_idx.begin(); it != frequency_to_idx.end(); it++) {
            kth_largest.push({ it->second, it->first });
            if (kth_largest.size() > k) kth_largest.pop();
        }
        vector<int> answer;
        while (!kth_largest.empty()) {
            answer.push_back(kth_largest.top().second);
            kth_largest.pop();
        }
        return answer;
    }
};
