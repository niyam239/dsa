/** 
	Problem : Find the Difference
	topics : string, hashing
	time complexitiy: O(N + M) where, N = size of str t, M = size of str s
	space complexity: O(26) 
	problem link: https://leetcode.com/problems/find-the-difference/submissions/
**/

class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> freq(26, 0);
        
        for(char it : t) {
            freq[it - 'a']++;
        }
        for(char it : s) {
            freq[it - 'a']--;
        }
        char res;
        for(int i=0; i<26; i++) {
            if(freq[i] == 1){
                res = (i + 'a');
                break;
            }
        }
        return res;
    }
};

