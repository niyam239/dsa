/** 
	Problem : valid mountain array
	approach : brute force
	time complexitiy: O(n)
	space complexity: O(n)
	problem link: https://leetcode.com/problems/valid-mountain-array/
**/

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int i = 0, n = arr.size();
        if(n < 3) return false;
        //traverse on up-sides in mountain
        while(i+1 < n && arr[i] < arr[i+1]) {
            i++;
        }
        //corner case // check mountains has up-side in begining or not
        if(i == 0 || i == n-1)  return false;
        
        //traverse on down-sides in mountain
        while(i+1 < n && arr[i] > arr[i+1]) {
            i++;
        }        
        
        //corner case // check mountains has down-side in end or not
        if(i == n-1)    return true;
        else    return false;
    }
};
