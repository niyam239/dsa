/** 
	Problem : Recover the Original Array
	topics : sorting, hashing, array
	time complexitiy: O(N^2 * logN)
	space complexity: O(N)
	problem link: https://leetcode.com/problems/recover-the-original-array/
**/

class Solution {
public:
    vector<int> recoverArray(vector<int>& a) {
        sort(a.begin(), a.end());
        for(int i=1; i<a.size(); i++) {
            int k = a[i] - a[0];
            if(k == 0 || k % 2 == 1) continue;
            
            multiset<int> ms(a.begin(), a.end());
            vector<int> ans;
            while(ms.size() > 0) {
                int val = *ms.begin();
                ms.erase(ms.begin());
                
                auto it = ms.find(val + k);
                if(it == ms.end()) break;
                ms.erase(it);
                ans.push_back(val + k / 2);
            }
            if(ans.size() == a.size()/2) 
                return ans;
        }
        return {};
    }
};

