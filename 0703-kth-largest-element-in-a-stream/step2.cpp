class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> kth_largest;
    int K;

    KthLargest(int k, vector<int>& nums) : K(k) {
        for(int num : nums) {
            kth_largest.push(num);
            if (kth_largest.size() > K) kth_largest.pop();
        }
    }

    int add(int val) {
        kth_largest.push(val);
        if (kth_largest.size() > K) kth_largest.pop();
        return kth_largest.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
