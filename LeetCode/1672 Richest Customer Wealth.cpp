/** 
	Problem : Richest Customer Wealth
	topics : matrix, linear approach
	time complexitiy: O(n * m)
	space complexity: O(1)
	problem link: https://leetcode.com/problems/richest-customer-wealth/submissions/
**/

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int n = accounts.size(), m = accounts[0].size();
        int maxWealth = 0;
        for(int i=0; i<n; i++) {
            int ithWealth = 0;
            for(int j=0; j<m; j++) {
                ithWealth += accounts[i][j];
            }
            maxWealth = max(maxWealth, ithWealth);
        }
        return maxWealth;
    }
};
