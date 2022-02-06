/** 
	Problem : Remove Duplicates from Sorted Array II
	topics : two pointer
	time complexitiy: O(N)
	space complexity: O(1)
	problem link: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
**/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int curr = 1, last = nums[0], cnt = 1;
        for(int i=1; i<nums.size(); i++) {
            if(nums[i] == last) {
                cnt++;
            }
            else {
                last = nums[i];
                cnt = 1;
            }
            
            if(cnt <= 2) {
                nums[curr++] = nums[i];
            }
            
        }
        
        return curr;
    }
};

