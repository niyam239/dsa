/** 
	Problem : Longest Palindrome by Concatenating Two Letter Words
	topics : string, hashing
	time complexitiy: O(n * len)
	space complexity: O(n)
					 where n = size of vector
					 len = max. string size
	problem link: https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/
**/

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int ans = 0;
        map<string, int> mp;
        for(string it : words) {
            string rev = it;
            reverse(rev.begin(), rev.end());
            if(mp.find(rev) != mp.end() && mp[rev] > 0) {
                mp[rev]--;
                ans += 4;
            } else {
                mp[it]++;
            }
            
        }
        int flag = 0;
        for(auto it : mp) {
            if(it.second > 0 && it.first[0] == it.first[1]) {
                ans += 2;
                break;
            }
        }
        return ans;
    }
};
