class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set_of_nums1(nums1.begin(), nums1.end());
        unordered_set<int> answer;

        for (int num2 : nums2) {
            if (set_of_nums1.count(num2)) {
                answer.insert(num2);
            }
        }

        return vector<int>(answer.begin(), answer.end());
    }
};
