/** 
	Problem : Stone Game
	topics : dp
	time complexitiy: O(n * n)
	space complexity: O(n * n)
	problem link: 
**/

class Solution {
public:
    int solve(int i, int j, vector<int> &piles, vector<vector<int>> &dp) {
        if(i > j) return 0;
        if(dp[i][j] == -1) return dp[i][j];
        
        return dp[i][j] = max(piles[i] - solve(i+1, j, piles, dp), piles[j] - solve(i, j-1, piles, dp));
    }
    bool stoneGame(vector<int>& piles) {
        //here alex can pick every even position integer or odd position integer
        // and in question mention that sum of all numbers is odd...
        //so either sum of all odd position or sum of all even position is higher
        // so alex always wins the game
        // sol: return true;
        // here, time & space complexity: O(1)
        
        //dp approach
        int n = piles.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        return solve(0, n-1, piles, dp);
    }
};
