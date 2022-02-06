/** 
	Problem : Smallest Value of the Rearranged Number
	topics : bit-manupulation, sorting, math
	time complexitiy: O(log n)
	space complexity: O(log n)
	problem link: https://leetcode.com/problems/smallest-value-of-the-rearranged-number/
**/

class Solution {
public:
    long long smallestNumber(long long num) {
        // negative value
        if(num < 0) {
            num = num*-1;
            vector<int> arr;
            long long temp = num;
            while(temp != 0) {
                int digit = temp%10;
                temp = temp/10;
                arr.push_back(digit);
            }
            sort(arr.begin(),arr.end(),greater<int>());
            temp = 0;
            for(int i=0;i<arr.size(); i++) {
                temp = temp*10LL + arr[i];
            }
            temp*= -1;
            return temp;
        }
        //zero
        else if(num == 0) {
            return 0;
        }
        //positive value
        else {
            vector<int> arr;
            long long temp = num;
            while(temp != 0) {
                int digit = temp%10;
                temp = temp/10;
                arr.push_back(digit);
            }
            sort(arr.begin(),arr.end());
            temp = 0;
            // to avoid preceding zeroes
            int i = 0;
            while(i < arr.size() && arr[i] == 0) {
                i++;
            }
            swap(arr[0], arr[i]);
            
            for(int i=0;i<arr.size(); i++) {
                temp = temp*10LL + arr[i];
            }

            return temp;
        }
    }
};
