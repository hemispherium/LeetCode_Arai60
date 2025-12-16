// 最初このコードを書いてTLE

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int, vector<int>>> kth_smallest;
        for (int num1 : nums1) {
            for (int num2 : nums2) {
                kth_smallest.push({num1 + num2, { num1, num2 }});
                if (kth_smallest.size() > k) kth_smallest.pop();
            }
        }
        vector<vector<int>> answer;
        while (!kth_smallest.empty()) {
            answer.push_back(kth_smallest.top().second);
            kth_smallest.pop();
        }
        return answer;
    }
};

// Naoto Iwaseさんのコードを参考に修正したもの

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<>
        > smallest;

        for (int j = 0; j < nums2.size() && j < k; ++j) {
            smallest.push({nums1[0] + nums2[j], {0, j}});
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
