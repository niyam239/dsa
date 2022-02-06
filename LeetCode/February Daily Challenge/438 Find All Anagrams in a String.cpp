/** 
	Problem : Find All Anagrams in a String
	topics : sliding window technique, anagram
	time complexitiy: O(n)
	space complexity: O(1)
	problem link: https://leetcode.com/problems/find-all-anagrams-in-a-string/
**/

class Solution {
public:
    //TC - O(26) as vector size is fixed we can consider as O(1)
    bool isValidAnagram(vector<int> &temp, vector<int> &pattern) {
        for(int i=0; i<temp.size(); i++) {
            if(temp[i] != pattern[i]) {
                return false;
            }
        }
        return true;
    }
    
    vector<int> findAnagrams(string s, string p) {
        if(s.size() < p.size()) {
            return {};
        }
        
        vector<int> temp(26, 0), pattern(26, 0);
        vector<int> ans;
        
        //count the char in pattern & first substr [0, p.size()]
        for(int i=0; i<p.size(); i++) {
            pattern[p[i] - 'a']++;
            temp[s[i] - 'a']++;
        }
        //if substr [0, p.size()] is valid anagram then add it in answer
        if(isValidAnagram(temp, pattern)) {
            ans.push_back(0);
        } 
        
        for(int i=p.size(); i < s.size(); i++) {
    
            //for counting the char in substr [i - p.size() + 1, i] 
            //delete char s[i - p.size()] & add char s[i] in temp
            temp[s[i - p.size()] - 'a']--;
            temp[s[i] - 'a']++;
            
            //if substr [i - p.size() + 1, i] is valid anagram then add it in answer
            if(isValidAnagram(temp, pattern)) {
                ans.push_back(i - p.size() + 1);
            }    
        }
        
        return ans;
    }
};
