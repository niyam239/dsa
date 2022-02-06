/** 
	Problem : Rearrange Array Elements by Sign
	approach : brute force
	time complexitiy: O(n) 
	space complexity: O(n)
	problem link: https://leetcode.com/problems/rearrange-array-elements-by-sign/
**/

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> pos, neg;
        for(int i=0; i<n; i++) {
            if(nums[i] < 0) {
                neg.push_back(nums[i]);
            }
            else {
                pos.push_back(nums[i]);
            }
        }
        int j = 0, k = 0;
        for(int i=0;i<n;i++) {
            if(i % 2 == 0) {
                nums[i] = pos[j++];
            }
            else {
                nums[i] = neg[k++];
            }
        }
    
        return nums;
    }
};
