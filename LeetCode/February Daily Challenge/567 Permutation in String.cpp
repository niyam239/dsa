/** 
	Problem : Permutation in String
	topics : sliding window technique
	time complexitiy: O(n) where n = size of str s2
	space complexity: O(1)
	problem link: https://leetcode.com/problems/permutation-in-string/
**/

class Solution {
public:
    //here this problem can be solved using sliding window technique
    bool checkInclusion(string s1, string s2) {
        if(s2.size() < s1.size()) {
            return false;
        }
        
        vector<int> str(26, 0), pattern(26, 0);
        
        for(int i=0; i<s1.size(); i++) {
            str[s2[i] - 'a']++;
            pattern[s1[i] - 'a']++;
        }
        if(pattern == str) {
            return true;
        }
        
        for(int i=s1.size(); i<s2.size(); i++) {
            str[s2[i - s1.size()] - 'a']--;
            str[s2[i] - 'a']++;
            
            if(str == pattern){
                return true;
            }
        }
        return false;
    }
};
