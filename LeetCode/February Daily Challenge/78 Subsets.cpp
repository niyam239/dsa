/** 
	Problem : Subsets 
	topics : backtracking, 
	time complexitiy: O(N * 2^N)
	space complexity: O(N) 
	problem link: https://leetcode.com/problems/subsets/
**/

class Solution {
public:
    void findSubSets(int ind, vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans) {
        if(ind == nums.size()) {
            ans.push_back(ds);
            return ;
        }
        //take
        ds.push_back(nums[ind]);
        findSubSets(ind+1, nums, ds, ans);
        
        //not take
        ds.pop_back();
        findSubSets(ind+1, nums, ds, ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        findSubSets(0, nums, ds, ans);
        return ans;
    }
};

