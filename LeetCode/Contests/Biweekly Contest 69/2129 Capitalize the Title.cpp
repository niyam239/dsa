/** 
	Problem : Capitalize the Title
	topics : string
	time complexitiy: O(n)
	space complexity: O(n) 
					where n is no. of char
	problem link: https://leetcode.com/problems/capitalize-the-title/
**/

class Solution {
public:
    string capitalizeTitle(string title) {
        stringstream s(title);
        string ans = "";
        string word;
        while(s >> word) {
            if(word.size() <= 2 ) {
                transform(word.begin(), word.end(), word.begin(), ::tolower);
                ans += word + " ";
            }
            else {
                ans += toupper(word[0]);
                word = word.substr(1);
                transform(word.begin(), word.end(), word.begin(), ::tolower);
                ans += word + " ";
            }
        }
        if(ans.size() > 0) ans.pop_back();
        return ans;
    }
};

