/** 
	Problem : Minimum Cost of Buying Candies With Discount
	approach : Greedy, Sorting
	time complexitiy: O(n * log n) 
	space complexity: O(1)
	problem link: https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount/
**/

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end());
        int totalCost = 0;
        int i = cost.size() - 1;
        // here, first we bought last 2 candies and get 1 for free
        // as array is sorted in asc order...
        while(i >= 0) {
            totalCost += cost[i--];
            if(i >= 0) totalCost += cost[i--];
            if(i >= 0) i--;
        }
        return totalCost;
    }
};
