/** 
	Problem : Destroying Asteroids
	topics : sorting, greedy 
	time complexitiy: O(N * Log N)
	space complexity: O(1)
	problem link: https://leetcode.com/problems/destroying-asteroids/
**/

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& ast) {
        sort(ast.begin(), ast.end());
        long long int m = mass;
        for(int i=0; i<ast.size(); i++) {
            if(ast[i] > m) {
                return false;
            }
            m += ast[i];
        }
        return true;
    }
};
