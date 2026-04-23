class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        const int INF = 1e9;

        vector<int> min_coins(amount + 1, INF);
        min_coins[0] = 0;

        for (int i = 0; i <= amount; i++) {
            for (int coin : coins) {
                if (i <= amount - coin) {
                    min_coins[i + coin] = min(min_coins[i + coin], min_coins[i] + 1);
                }
            }
        }
        return min_coins[amount] == INF ? -1 : min_coins[amount];
    }
};
