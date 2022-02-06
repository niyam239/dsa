/** 
	Problem : Minimum Swaps to Group All 1's Together II
	topics : prefix-sum
	time complexitiy: O(n)
	space complexity: O(n)
	problem link: https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/
**/

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int noOfOnes = 0;
        for(int i=0; i<nums.size(); i++) {
            noOfOnes += nums[i];
        }
        int n = nums.size();
        int x = noOfOnes;
        if(x == n || n == 1 || x == 0) {
            return 0;
        }
        long long int maxOnes = INT_MIN;
        
        vector<int> pre(n, 0);
        
        pre[0] = nums[0];
        for(int i=1; i<n; i++) {
            pre[i] = pre[i-1] + nums[i];
        }
        
        for(int i=x-1; i<n; i++) {
            if(i == (x-1)) {
                noOfOnes = pre[i];
            }
            else {
                noOfOnes = pre[i] - pre[i-x];
            }
            
            if(maxOnes < noOfOnes) {
                maxOnes = noOfOnes;
            }
        }

        for(int i=-1; i<x; i++) {
            if(i == (x-1)) {
                noOfOnes = pre[i];
            }
            if(i == -1) {
                noOfOnes = pre[n-1] - pre[n-1-x];
            }
            else {
                noOfOnes = pre[i] + pre[n-1] - pre[n-1-x+i+1];
            }
            
            if(maxOnes < noOfOnes) {
                maxOnes = noOfOnes;
            }
        }

        int noOfZeros = x - maxOnes;
        
        return noOfZeros;
    }
};
