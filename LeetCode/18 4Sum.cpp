/** 
	Problem : 4Sum
	topics : two pointer
	time complexitiy: O(N ^ 3 + N*Log N)
	space complexity: O(1)
	problem link: https://leetcode.com/problems/4sum/submissions/
**/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size() < 4) 
            return {};
        
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        
        for(int i=0; i<nums.size() - 3; i++) {
            if(i == 0 || (i > 0 && nums[i] != nums[i-1])){
                for(int j=i+1; j<nums.size() - 2; j++) {
                    if(j == i+1 || (j > i && nums[j] != nums[j-1])) {
                        int low = j+1, high = nums.size()-1, sum = target - nums[i] - nums[j];

                        while(low < high) {
                            if(nums[low] + nums[high] == sum) {
                                ans.push_back({nums[i], nums[j], nums[low], nums[high]});

                                while(low < high && nums[low] == nums[low + 1]) low++;
                                while(low < high && nums[high] == nums[high - 1]) high--;

                                low++, high--;
                            }
                            else if(nums[low] + nums[high] < sum) {
                                low++;
                            }
                            else {
                                high--;
                            }
                        }
                    }
                }
            }
        }
        
        return ans;
    }
};
