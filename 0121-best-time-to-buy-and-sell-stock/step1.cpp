class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if (size == 1) {
            return 0;
        }
        int max_profit =  -1;
        vector<int> min_price(size, 100000);
        min_price[0] = prices[0];
        for (int i = 1; i < size; i++) {
            min_price[i] = min(min_price[i - 1], prices[i]);
            max_profit = max(max_profit, prices[i] - min_price[i]);
        }
        return max_profit;
    }
};
