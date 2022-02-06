/** 
	Problem : Minimum Time to Remove All Cars Containing Illegal Goods
	topics : prefix-suffix
	time complexitiy: O(N)
	space complexity: O(N)
	problem link: https://leetcode.com/problems/minimum-time-to-remove-all-cars-containing-illegal-goods/
**/


class Solution {
public:
    int minimumTime(string s) {
        vector<int> pre(s.size(), 0), suf(s.size(), 0);
        // prefix
        for(int i=0; i<s.size(); i++) {
            if(i == 0) {
                pre[i] = s[i] - '0';
            }
            else {
                if(s[i] == '1')
                    pre[i] = min(pre[i-1] + 2, i + 1);
                else
                    pre[i] = pre[i-1];
            }
        }
        // suffix
        for(int i=s.size()-1; i>=0; i--) {
            if(i == s.size()-1) {
                suf[i] = s[i] - '0';
            }
            else {
                if(s[i] == '1')
                    suf[i] = min(suf[i+1] + 2, int(s.size() - i));
                else
                    suf[i] = suf[i+1];
            }
        }
        
        int ans = INT_MAX;
        // find the minimum answer
        for(int i=0; i<s.size()-1; i++) {
            ans = min(ans, pre[i] + suf[i+1]);  
        }
        
        // this corner case required as above for loop runs only is size fo str > 1
        if(s.size() == 1) {
            return pre[0];
        }
        
        //if string not contains any 1's
        if(ans == INT_MAX)
            ans = 0;
        return ans;
    }
};
