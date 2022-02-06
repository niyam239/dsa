/** 
	Problem : Minimum Moves to Reach Target Score
	topics : greedy, math
	time complexitiy: O(log n)
	space complexity: O(1)
					where, n = target number 
	problem link: https://leetcode.com/problems/minimum-moves-to-reach-target-score/
**/

class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int ans = 0;
        int res = maxDoubles;
        int x = target;
        while(x > 2 && res > 0 ) {
            if(x % 2 == 1) ans++;
            x = x >> 1;
            ans++;
            res--;
        }
        ans += x - 1;
        return ans;
    }
};

