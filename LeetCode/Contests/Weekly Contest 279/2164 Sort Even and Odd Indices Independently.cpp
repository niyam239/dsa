/** 
	Problem : Sort Even and Odd Indices Independently
	topics : sorting
	time complexitiy: O(N)
	space complexity: O(N)
	problem link: https://leetcode.com/problems/sort-even-and-odd-indices-independently/
**/

class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> odd, even;
        for(int i=0;i<nums.size();i++) {
            if(i%2 == 0) {
                even.push_back(nums[i]);
            }
            else {
                odd.push_back(nums[i]);
            }
        }
        sort(odd.begin(), odd.end(), greater<int>());
        sort(even.begin(), even.end());
        
        for(int i=0;i<nums.size();i++) {
            if(i%2 == 0) {
                nums[i] = even[i/2];
            }
            else {
                nums[i] = odd[i/2];
            }
        }
        return nums;
    }
};
