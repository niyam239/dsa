/** 
	Problem : Solving Questions With Brainpower
	topics : dp
	time complexitiy: O(N)
	space complexity: O(N) 
	problem link: https://leetcode.com/problems/solving-questions-with-brainpower/
**/

class Solution {
public:
    long long mostPoints(vector<vector<int>>& q) {
        long long n = q.size();
        vector<long long> dp(n+1, 0);
        long long ans = 0;
        
        for(int i=n-1; i>=0; i--) {
            dp[i] = q[i][0];
            if(q[i][1] + i + 1 < n) {
                dp[i] += dp[i + q[i][1] + 1];
            }
            if(i<n-1) {
                dp[i] = max(dp[i], dp[i+1]);
            }

            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
