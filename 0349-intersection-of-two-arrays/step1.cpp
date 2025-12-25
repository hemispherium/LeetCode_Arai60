class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> set1, set2;
        for (int num1 : nums1) {
            set1.insert(num1);
        }
        for (int num2 : nums2) {
            set2.insert(num2);
        }
        vector<int> answer;
        for (int i = 0; i <= 1000; i++) {
            if (set1.contains(i) && set2.contains(i)) {
                answer.push_back(i);
            }
        }
        return answer;
    }
};
