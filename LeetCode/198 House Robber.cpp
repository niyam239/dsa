/** 
	Problem : House Robber
	topics : dp
	time complexitiy: O(n)
	space complexity: O(n)
	problem link: https://leetcode.com/problems/house-robber/
**/


class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        vector<int> dp(n+1, 0);
        //base case
        dp[0] = nums[0];
        if(n > 1)
            dp[1] = max(nums[1], nums[0]);
        
        //tabulation: recursive calls
        for(int i=2; i<n; i++) {
            int take = nums[i] + dp[i-2];
            int notTake = dp[i-1];
            
            dp[i] = max(take, notTake);
        }
        
        return dp[n-1];
    }
};
