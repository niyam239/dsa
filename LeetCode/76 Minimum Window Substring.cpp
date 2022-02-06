/** 
	Problem : Minimum Window Substring
	topics : sliding window technique
	time complexitiy: O(n + m) where n = size of string:s
									 m = size of string:t
	space complexity: O(1) // here exactly O(60) but we can consider as O(1)
	problem link: https://leetcode.com/problems/minimum-window-substring/submissions/
**/

class Solution {
public:
    bool isValid(vector<int> &temp, vector<int> &pattern) {
        for(int i=0; i<temp.size(); i++) {
            if(pattern[i] > temp[i]) {
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        if(s.size() < t.size()) {
            return "";
        }
        vector<int> temp(60, 0), pattern(60, 0);
        for(int i=0; i<t.size(); i++) {
            pattern[t[i] - 'A']++;
        }
        
        int i = 0;
        while(i < s.size() && !isValid(temp, pattern)) {
            temp[s[i] - 'A']++;
            i++;
        }
        int start = 0, end = i-1;
        string res = "";
        
        while(start < end) {
            temp[s[start] - 'A']--;
            if(isValid(temp, pattern)) {
                start++;
            } 
            else {
                temp[s[start] - 'A']++;
                break;
            }
        }
        
        if(isValid(temp, pattern)){
            res = s.substr(start, end - start + 1);
        }
        //cout<<end<<" ";
        
        for(int j=i; j<s.size(); j++) {
            temp[s[j] - 'A']++;
            end++;
            while(start < end) {
                temp[s[start] - 'A']--;
                if(isValid(temp, pattern)) {
                    start++;
                } 
                else {
                    temp[s[start] - 'A']++;
                    break;
                }
            }
            if(end - start + 1 < res.size()) {
                res = s.substr(start, end - start + 1);
            }
        }
        
        return res;
    }
};
