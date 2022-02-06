/** 
	Problem : Intervals Between Identical Elements
	topics : hashing
	time complexitiy: O(N * log N) where log N for map insertion
	space complexity: O(N)
	problem link: https://leetcode.com/problems/intervals-between-identical-elements/
**/

typedef long long ll;
#define F first
#define S second

class Solution {
public:
    vector<ll> getDistances(vector<int>& arr) {
        int n = arr.size();
        vector<ll> dist(n, 0);
        
        map<int,vector<int>> mp;
        for(int i=0; i<n; i++) {
            mp[arr[i]].push_back(i);
        }
        
        for(auto it : mp) {
            if(it.S.empty()) continue;
            ll temp = 0;
            auto vec = it.S;
            for(int i=0; i<vec.size(); i++) {
                temp += vec[i];
                dist[vec[i]] += (ll)(i+1)*vec[i] - temp;
            }
            temp = 0;
            for(int i=vec.size()-1; i>=0; i--) {
                temp += vec[i];
                dist[vec[i]] += temp - (ll)(vec.size() - i)*vec[i];
            }
            
        }
        
        return dist;
    }
};
