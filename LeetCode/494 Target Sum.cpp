/** 
	Problem : target sum
	approach : dp
	time complexitiy: O(n*sum)
	space complexity: O(n*sum)
	problem link: https://leetcode.com/problems/target-sum/
**/

class Solution {
public:
    int solve(int index, int curSum, vector<int> &nums, int target, vector<vector<int>> &dp) {
        //here, i have taken curSum + 1000 bcoz => curSum may have negative val
        //base case
        if(index < 0) {
            return (curSum == target);
        }
        //memoization
        if(dp[index][curSum+1000] != -1) return dp[index][curSum+1000];
        
        //recursive calls
        int positive = solve(index - 1, curSum + nums[index], nums, target, dp);
        int negative = solve(index - 1, curSum - nums[index], nums, target, dp);
        
        return dp[index][curSum+1000] = positive + negative;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int curSum = 0;
        vector<vector<int>> dp(n, vector<int> (2100, -1));
        return solve(n-1, curSum, nums, target, dp);
    }
};
