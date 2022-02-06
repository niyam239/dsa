/** 
	Problem : Delete and Earn
	topics : dp
	time complexitiy: O(10^5)
	space complexity: O(10^5)
	problem link: https://leetcode.com/problems/delete-and-earn/
**/


class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int mx = 5+1e5;
        vector<int> dp(mx, 0);
        
        //base case
        for(auto it: nums) {
            dp[it] += it;
        }
        
        //tabulation: recursive calls
        for(int i=3; i<mx; i++) {
            dp[i] += max(dp[i-3], dp[i-2]);
        }
        
        return max(dp[mx-1], dp[mx-2]);
    }
};
