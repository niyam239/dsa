/** 
	Problem : Earliest Possible Day of Full Bloom
	topics : sorting, greedy
	time complexitiy: O(N * log N)
	space complexity: O(2 * N) 
	problem link: https://leetcode.com/problems/earliest-possible-day-of-full-bloom/
**/

class Solution {
public:
    int earliestFullBloom(vector<int>& p, vector<int>& g) {
        vector<pair<int,int>> v;
        int n = p.size();
        for(int i=0;i<n;i++) {
            v.push_back({p[i], g[i]});
            
        }
        
        sort(v.begin(), v.end(), [] (pair<int,int> p1, pair<int,int> p2) {
            if(p1.second == p2.second) {
                return p1.first > p2.first;
            }
            return p1.second > p2.second;
        });
        
        int day = 0;
        int prev = 0;
        for(int i=0;i<n;i++) {
            int a = v[i].first;
            int b = v[i].second;
            day = max(day, prev + a + b);
            prev += a; 
        }
        return day;
    }
};
