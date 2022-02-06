/** 
	Problem : Best Time to Buy and Sell Stock
	topics : greedy
	time complexitiy: O(n)
	space complexity: O(1)
	problem link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
**/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn = INT_MAX; 
        int ans = 0;
        for(int i=0; i<prices.size(); i++) {
            if(prices[i] > mn) {
                ans = max(ans, prices[i] - mn);
            }
            
            mn = min(mn, prices[i]);
        }
        return ans;
    }
};
