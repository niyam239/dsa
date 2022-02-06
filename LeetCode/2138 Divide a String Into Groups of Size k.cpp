/** 
	Problem : Divide a String Into Groups of Size k
	topics : string
	time complexitiy: O(N)
	space complexity: O(1) 
	problem link: https://leetcode.com/problems/divide-a-string-into-groups-of-size-k/
**/

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        int n = s.size();
        int rem = k - n % k;
        string temp = "";
        for(int i=0; i<n; i++) {
            if(i != 0 && i%k == 0) {
                ans.push_back(temp);
                temp = "";
            }
            temp.push_back(s[i]);
        }
        for(int i=temp.size(); i<k; i++) {
            temp = temp + fill;
        }
        ans.push_back(temp);
        return ans;
        
    }
};
