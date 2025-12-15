// 元々書いていたコード

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> kth;

    KthLargest(int k, vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        for (int i = 0; i < k; i++) {
            kth.push(nums[i]);
        }
    }

    int add(int val) {
        if (kth.empty()) {
            kth.push(val);
        } else if (kth.top() < val) {
            kth.pop();
            kth.push(val);
        }
        return kth.top();
    }
};

// GPTが修正したコード

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> kth;
    int K;

    KthLargest(int k, vector<int>& nums) : K(k) {
        for (int n : nums) {
            kth.push(n);
            if (kth.size() > K) kth.pop();
        }
    }

    int add(int val) {
        kth.push(val);
        if (kth.size() > K) kth.pop();
        return kth.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
