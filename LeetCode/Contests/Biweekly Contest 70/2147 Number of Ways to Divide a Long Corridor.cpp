/** 
	Problem : Number of Ways to Divide a Long Corridor
	approach : greedy, math
	time complexitiy: O(n) 
	space complexity: O(1)
	problem link: https://leetcode.com/problems/number-of-ways-to-divide-a-long-corridor/
**/

#include<bits/stdc++.h>
const int mod = 1e9 + 7;
class Solution {
public:
    int numberOfWays(string corridor) {
        long long int res = 1;
        int count = 0;
        int last = 0;
        int n = corridor.size();
        for(int i=0; i<n; i++) {
            if(corridor[i] == 'S'){
                count++;
                if(count > 2) {
                    res = (res * (i - last)) % mod;
                    count = count % 2;
                }
                last = i;
            }
        }
        if(count == 2) {
            return res;
        }
        else {
            return 0;
        }
    }
};
