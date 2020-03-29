class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty() || prices.size() < 2)
            return 0;

        int sell = 0;
        int prev_sell = 0;
        int buy = -99999999;
        int prev_buy;

        for (int i = 0; i < prices.size(); i++) {
            prev_buy = buy;
            buy = (prev_sell - prices[i] > prev_buy) ? prev_sell - prices[i] : prev_buy;
            prev_sell = sell;
            sell = (prev_buy + prices[i] > prev_sell) ? prev_buy + prices[i] : prev_sell;
        }
        return sell;
    }
};