/** 
	Problem : Count Words Obtained After Adding a Letter
	topics : string , hashing
	time complexitiy: O(n * len * log(len)) 
					here, len * log(len) for sorting string
	space complexity: O(n * len)
					where, n = size of vector
						  len = max. size of string
	problem link: https://leetcode.com/problems/count-words-obtained-after-adding-a-letter/
**/

class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        map<string, int> mp;
        
        for(string it : startWords) {
            string s = it;
            sort(s.begin(), s.end());
            mp[s]++;
        }
        
        int count = 0;
        for(string it : targetWords) {
            string s = it;
            sort(s.begin(), s.end());
            for(int i=0; i<s.size(); i++) {
                string temp = s.substr(0,i) + s.substr(i+1);
                if(mp.find(temp) != mp.end()) {
                    count++;
                    break;
                }
            }
             
        }
        return count;
    }
};

