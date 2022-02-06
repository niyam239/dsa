/** 
	Problem : Number of Laser Beams in a Bank
	topics : math
	time complexitiy: O(N)
	space complexity: O(1) 
	problem link: https://leetcode.com/problems/number-of-laser-beams-in-a-bank/
**/

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        int prev = 0;
        int ans = 0;
        
        for(int i=0; i<n; i++) {
            int curr = 0;
            for(auto it : bank[i]) {
                if(it == '1') curr++; 
            }
            if(curr > 0){
                if(prev > 0) {
                    ans += prev*curr;
                }
                prev = curr;    
            }
            
        }
        return ans;
    }
};
