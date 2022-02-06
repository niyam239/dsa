/** 
	Problem : triangle
	approach : dp
	time complexitiy: O(n*n)
	space complexity: O(n*n)
	problem link: https://leetcode.com/problems/triangle/
**/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int> (n, 0));
        
        //base case
        for(int i=0; i<n; i++) {
            dp[n-1][i] = triangle[n-1][i];
        }
        
        //recursive calls
        for(int i=n-2; i>=0; i--) {
            for(int j=i; j>=0; j--) {
                int down = triangle[i][j] + dp[i+1][j];
                int downDiagonal = triangle[i][j] + dp[i+1][j+1];
            
                //choose minimum val
                dp[i][j] = min(down, downDiagonal);
            }
        }
        return dp[0][0];
    }
};
