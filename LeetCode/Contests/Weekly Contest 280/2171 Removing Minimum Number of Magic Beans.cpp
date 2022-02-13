/** 
	Problem : Removing Minimum Number of Magic Beans
	topics : prefix sum 
	time complexitiy: O(N * log N)
	space complexity: O(1) 
	problem link: https://leetcode.com/problems/removing-minimum-number-of-magic-beans/
**/

class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(), beans.end());
        long long sum = 0;
        for(auto it : beans) {
            sum += it;
        }
        long long curr = 0;
        long long ans = sum;
        
        for(int i=0; i<beans.size(); i++) {
            curr += beans[i];
            sum -= beans[i];
            ans = min(ans, curr + (sum - (long long)(beans.size()-i) * beans[i]));
        }
        
        return ans;
    }
};

