class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 1) {
            return 0;
        }

        int before_buy = 0;
        int holding = -100000;
        int after_sell = 0;

        for (int price : prices) {
            holding = max(holding, before_buy - price);
            after_sell = max(after_sell, holding + price);
        }
        return after_sell;
    }
};
