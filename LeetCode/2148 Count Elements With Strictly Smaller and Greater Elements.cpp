/** 
	Problem : Count Elements With Strictly Smaller and Greater Elements
	approach : sorting
	time complexitiy: O(n * log n) 
	space complexity: O(1)
	problem link: https://leetcode.com/problems/count-elements-with-strictly-smaller-and-greater-elements/
**/

class Solution {
public:
    int countElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 1, j = nums.size()-2;
        while(i < n && nums[i-1] == nums[i]) {
            i++;
        }
        while(j >= 0 && nums[j] == nums[j+1]) {
            j--;
        }
        int ans = max(0, j-i+1);
        return ans;
    }
};
