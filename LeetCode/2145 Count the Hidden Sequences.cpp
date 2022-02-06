/** 
	Problem : Count the Hidden Sequences
	approach : greedy, math
	time complexitiy: O(n) 
	space complexity: O(1)
	problem link: https://leetcode.com/problems/count-the-hidden-sequences/
**/

#include<bits/stdc++.h>
class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long int res = 0;
        long long int mn = 0, mx = 0;
        
        //find the range in between array elements are there
        for(int i=0; i<differences.size(); i++) {
            res += differences[i];
            mn = min(mn, res);
            mx = max(mx, res);
        }
        
        long long int ans = (upper - lower) - (mx - mn) + 1;
        //ensure that ans never have non-zero answer
        ans = max(0LL, ans);
        return ans;
    }
};
