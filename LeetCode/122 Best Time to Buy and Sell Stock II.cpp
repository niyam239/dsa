/** 
	Problem : Best Time to Buy and Sell Stock II
	topics : greedy
	time complexitiy: O(n)
	space complexity: O(1)
	problem link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
**/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sum = 0;
        
        for(int i=1; i<prices.size(); i++) {
            if(prices[i] > prices[i-1]) {
                sum += prices[i] - prices[i-1];
            }
        }
        
        return sum;
    }
};
