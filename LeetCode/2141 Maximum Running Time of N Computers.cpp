/** 
	Problem : Maximum Running Time of N Computers
	topics : greedy, sorting
	time complexitiy: O(N)
	space complexity: O(N * log N)
					where, N = no. of batteries 
	problem link: https://leetcode.com/problems/maximum-running-time-of-n-computers/
**/

#define ll long long
class Solution {
public:
    long long maxRunTime(int n, vector<int>& b) {
        sort(b.begin(), b.end(), greater<int> ());
        ll sum = accumulate(b.begin(), b.end(), 0LL);
        
        for(int i=0; i<b.size(); i++) {
            if(b[i] > sum / n) {
                sum -= b[i];
                n--;
            }
            else {
                return sum/n;
            }
        }
        return 0;
    }
};

