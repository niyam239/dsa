/** 
	Problem : N-th Tribonacci Number
	topics : dp
	time complexitiy: O(n)
	space complexity: O(n)
	problem link: https://leetcode.com/problems/n-th-tribonacci-number/
**/


class Solution {
public:
    int tribonacci(int n) {
        vector<int> t(n+1, 0);
        //base cases
        if(n>=1) t[1] = 1;
        if(n>=2) t[2] = 1;
        
        //tabulation: recursive calls
        for(int i=3; i<=n; i++){
            t[i] = t[i-1] + t[i-2] + t[i-3];
        }
        return t[n];
    }
};
