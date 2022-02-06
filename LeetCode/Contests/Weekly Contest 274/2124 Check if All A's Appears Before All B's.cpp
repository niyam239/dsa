/** 
	Problem : Check if All A's Appears Before All B's
	topics : string, maths
	time complexitiy: O(n) // n size of string
	space complexity: O(1)
	problem link: https://leetcode.com/problems/check-if-all-as-appears-before-all-bs/
**/

class Solution {
public:
    bool checkString(string s) {
        int n = s.size();
        int bflag = 0;
        for(int i=0; i<n; i++) {
            if(s[i] == 'b') bflag = 1;
            if(s[i] == 'a' && bflag == 1) return false;
        }
        return true;
    }
};
