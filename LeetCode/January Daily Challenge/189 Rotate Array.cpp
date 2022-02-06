/** 
	Problem : Rotate Array
	topics : two pointer
	time complexitiy: O(n)
	space complexity: O(1)
	problem link: https://leetcode.com/problems/rotate-array/
**/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        //corner case // if n & k is same, do nothing 
        if(n == k) {
            return ;
        }
        int loop = __gcd(n, k);
        
        for(int i=0; i<loop; i++) {
            int start = nums[i];
            int curr = nums[i];
            int prev = nums[i];
            int j = i;
            //loop will run intill we complete one cycle
            while((j+k)%n != i) {
                curr = nums[(j+k)%n];
                nums[(j+k)%n] = prev;
                prev = curr;
                j = (j+k)%n;
            }
            nums[(j+k)%n] = prev;
        }
    }
};
