/** 
	Problem : 3Sum
	topics : 2 pointer
	time complexitiy: O(N ^ 2 + NlogN)
	space complexity: O(1)
	problem link: https://leetcode.com/problems/3sum/
**/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() < 3) {
            return {};
        }
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        
        for(int i=0; i<nums.size()-2; i++) {
            if(i == 0 || (i > 0 && nums[i] != nums[i-1])) {
                int low = i+1, high = nums.size()-1, sum = 0 - nums[i]; // a = 0 - (b+c);
                
                while(low < high) {
                    if(nums[low] + nums[high] == sum) {
                        ans.push_back({nums[i], nums[low], nums[high]});
                        
                        while(low < high && nums[low] == nums[low+1]) low++;
                        while(low < high && nums[high] == nums[high-1]) high--;
                        
                        low++, high--;
                    }
                    else if(nums[low] + nums[high] > sum) {
                        high--;
                    }
                    else {
                        low++;
                    }
                }
            }
        }
        return ans;
    }
};
