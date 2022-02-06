/** 
	Problem : Find All Lonely Numbers in the Array
	topics : sorting, greedy, math
	time complexitiy: O(n * log n)
	space complexity: O(1)
	problem link: https://leetcode.com/problems/find-all-lonely-numbers-in-the-array/
**/

class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        //sort the array
        sort(nums.begin(), nums.end());
        //if element's just above & just after element is not present
        //then that element is lonely element.
        for(int i=0; i<n; i++) {
            bool flag = true;
            if(i > 0  && (nums[i-1] + 1 == nums[i] || nums[i-1] == nums[i])) {
                flag = false;
            }
            if(i < n-1 && (nums[i] + 1 ==nums[i+1] || nums[i] == nums[i+1])) {
                flag = false;
            }
            if(flag) {
                res.push_back(nums[i]);
            }
        }
        return res;
        
    }
};
