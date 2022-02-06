/** 
	Problem : Contiguous Array
	topics : prefix sum, hash table
	time complexitiy: O(N)
	space complexity: O(N)
	problem link: https://leetcode.com/problems/contiguous-array/
**/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size(), sum = 0, ans = 0;
        unordered_map<int,int> mp;
        
        mp[0] = -1;
        for(int i=0; i<n; i++) {
            sum += (nums[i] == 1 ? 1 : -1);
            if(mp.find(sum) != mp.end()) {
                 ans = max(ans, i - mp[sum]);
            }
            else {
                mp[sum] = i;
            }
        }
        
        return ans;
    }
};
