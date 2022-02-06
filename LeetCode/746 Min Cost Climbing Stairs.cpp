/** 
	Problem : Min Cost Climbing Stairs
	topics : dp
	time complexitiy: O(n)
	space complexity: O(n)
	problem link: https://leetcode.com/problems/min-cost-climbing-stairs/
**/


class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if(n == 1) return 0;
        vector<int> dp(n, 0);
        
        for(int i=0;i<n;i++) {
            //base case
            if(i<2) {
                dp[i] = cost[i];
            } 
            //tabulation: recursive call
            else {
                dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
            }
        }
        return min(dp[n-1], dp[n-2]);
    }
};
