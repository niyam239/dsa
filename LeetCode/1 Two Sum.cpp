/** 
	Problem : Two Sum
	topics : hashing
	time complexitiy: O(N)
	space complexity: O(N)
	problem link: https://leetcode.com/problems/two-sum/
**/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> mp;
        for(int i=0; i<nums.size(); i++){
            auto it = mp.find(target - nums[i]);
            
            if(it != mp.end()){
                return {it->second, i};
            }
            
            mp[nums[i]] = i;
        }
        return {0, 0};
    }
};
