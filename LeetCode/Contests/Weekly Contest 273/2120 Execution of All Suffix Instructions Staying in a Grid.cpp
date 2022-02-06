/** 
	Problem : Execution of All Suffix Instructions Staying in a Grid
	topics : string
	time complexitiy: O(N ^ 2)
	space complexity: O(1)
	problem link: https://leetcode.com/problems/execution-of-all-suffix-instructions-staying-in-a-grid/
**/

class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& st, string s) {
        vector<int> ans;
        for(int i=0; i<s.size(); i++) {
            int x = st[0], y = st[1];
            int cnt = 0;
            
            for(int j=i; j<s.size(); j++) {
                if(s[j] == 'L') y--;
                if(s[j] == 'R') y++;
                if(s[j] == 'U') x--;
                if(s[j] == 'D') x++;
                if(0 <= x && x < n && 0 <= y && y < n) {
                    cnt++;
                }
                else {
                    break;
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};
