/** 
	Problem : Check if Every Row and Column Contains All Numbers
	topics : matrix
	time complexitiy: O(n*n)
	space complexity: O(n*n)
					where n = size of col & row
	problem link: https://leetcode.com/problems/check-if-every-row-and-column-contains-all-numbers/
**/

class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        set<int> row[n], col[n];
        for(int i=0;i<n;i++) {
            for(int j=0; j<n;j++) {
                row[i].insert(matrix[i][j]);
                col[j].insert(matrix[i][j]);
            }
        }
        
        for(int i=0;i<n;i++) {
            if(row[i].size() != n || col[i].size() != n) {
                return false;
            }
        }
        return true;
    }
};
