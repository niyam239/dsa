/** 
	Problem : 4Sum II
	topics : hash table
	time complexitiy: O(N ^ 2)
	space complexity: O(n ^ 2)
	problem link: https://leetcode.com/problems/4sum-ii/
**/

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> mp;
        int ans = 0;
        
        for(auto it1 : nums1) {
            for(auto it2 : nums2) {
                mp[it1 + it2]++;
            }
        }
        
        for(auto it1 : nums3) {
            for(auto it2 : nums4) {
                if(mp.find(0 - it1 - it2) != mp.end()) {
                    ans += mp[0 - it1 - it2];
                }
            }
        }

        return ans;
    }
};
