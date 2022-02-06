/** 
	Problem : A Number After a Double Reversal
	topics : math
	time complexitiy: O(1)
	space complexity: O(1)
	problem link: https://leetcode.com/problems/a-number-after-a-double-reversal/
**/

class Solution {
public:
    bool isSameAfterReversals(int num) {
        if(num == 0) 
            return true;
        
        //if value having 0 at back then after two reversals num become diff.
        if (num % 10 == 0) 
            return false;
        else    
            return true;
    }
};
