/** 
	Problem : Minimum Operations to Make the Array Alternating
	topics : hashing, sorting 
	time complexitiy: O(N * log N)
	space complexity: O(N) 
	problem link: https://leetcode.com/problems/minimum-operations-to-make-the-array-alternating/
**/

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        if(nums.size() == 1) 
            return 0;
        
        map<int,int> mp1, mp2;
        for(int i=0; i<nums.size(); i++) {
            if(i % 2 == 0) {
                mp1[nums[i]]++;
            }
            else {
                mp2[nums[i]]++;
            }
        }
        int n = nums.size();
        
        int odd = n/2 + n%2;
        int even = n/2;
        vector<pair<int,int>> v1,v2;
        for(auto it : mp1) {
            v1.push_back({it.second, it.first});
        }
        for(auto it : mp2) {
            v2.push_back({it.second, it.first});
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        
        //case-1
        int x = v1.back().first;
        int val = v1.back().second;
        int y = v2.back().first;
        int vv = v2.back().second;
        if(val == vv) {
            if(v2.size() == 1) {
                y = 0;
            }
            else {
                y = v2[v2.size() - 2].first;
            }
        }
        int ans = (odd - x) + (even - y);
        
        //case - 2
        x = v2.back().first;
        val = v2.back().second;
        y = v1.back().first;
        vv = v1.back().second;
        if(val == vv) {
            if(v1.size() == 1) {
                y = 0;
            }
            else {
                y = v1[v1.size() - 2].first;
            }
        } 
        
        ans = min(ans, (odd - x) + (even - y));
        
        return ans;
    }
};

