class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold = -prices[0];
        int not_hold = 0;

        for (int i = 1; i < prices.size(); i++) {
            int new_hold = max(hold, not_hold - prices[i]);
            int new_not_hold = max(not_hold, hold + prices[i]);

            hold = new_hold;
            not_hold = new_not_hold;
        }

        return not_hold;
    }
};
