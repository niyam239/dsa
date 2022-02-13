/** 
	Problem : Count Operations to Obtain Zero
	topics : brute force 
	time complexitiy: O(N)
	space complexity: O(1) 
	problem link: https://leetcode.com/problems/count-operations-to-obtain-zero/
**/

class Solution {
public:
    int countOperations(int num1, int num2) {
        int cnt = 0;
        
        while(num1 != 0 && num2 != 0) {
            if(num1 < num2) 
                swap(num1, num2);
            
            num1 = num1 - num2;
            num2 = num2;
            cnt++;
        }
        return cnt;
    }
};

