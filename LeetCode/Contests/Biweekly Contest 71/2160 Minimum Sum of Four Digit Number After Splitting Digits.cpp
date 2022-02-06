/** 
	Problem : Minimum Sum of Four Digit Number After Splitting Digits
	topics : sorting
	time complexitiy: O(log n) + O(log n * log log n)
	space complexity: O(log n)
					// here, log has base 10
	problem link: https://leetcode.com/problems/minimum-sum-of-four-digit-number-after-splitting-digits/
**/

class Solution {
public:
    int minimumSum(int num) {
        vector<int> arr;
        int temp = num;
        while(temp != 0) {
            int digit = temp % 10;
            temp = temp / 10;
            if(digit > 0) {
                arr.push_back(digit);
            }
        }
        sort(arr.begin(), arr.end());
        int sum = 0;
        if(arr.size() <= 2) {
            for(auto it : arr) {
                sum += it;
            }
        }
        else if(arr.size() == 3) {
            sum += arr[2];
            sum += arr[0] * 10 + arr[1]; 
        }
        else {
            sum += arr[0] * 10 + arr[3];
            sum += arr[1] * 10 + arr[2];
        }
        return sum;
    } 
};
