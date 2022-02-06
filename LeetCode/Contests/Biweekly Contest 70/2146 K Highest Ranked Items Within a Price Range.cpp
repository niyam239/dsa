/** 
	Problem : K Highest Ranked Items Within a Price Range
	approach : BFS
	time complexitiy: O(n*m) + O(n*m log(n*m)) 
	space complexity: O(n*m) 
	problem link: https://leetcode.com/problems/k-highest-ranked-items-within-a-price-range/
**/

class Solution {
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        vector<vector<int>> ans;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));
        
        //add starting position
        queue<pair<pair<int,int>,int>> q;
        vis[start[0]][start[1]] = 1;
        int dist = 0;
        q.push({{start[0], start[1]}, dist});
        //declare 4 directions
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        
        while(!q.empty()) {
            auto curr = q.front();
            q.pop();
            int x = curr.first.first, y = curr.first.second;
            int dist = curr.second;
            
            //check if cell in pricing range
            if(pricing[0] <= grid[x][y] && grid[x][y] <= pricing[1]) {
                ans.push_back({dist, grid[x][y], x, y});
            }
            
            //check in all 4 direction
            for(int i=0; i<4; i++) {
                //initialize new indexes
                int nx = x + dx[i], ny = y + dy[i];
                if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] > 0 && vis[nx][ny] == 0) {
                    q.push({{nx, ny}, dist+1});
                    vis[nx][ny] = 1;
                }
            }
        }
        
        //sort the cells by given criteria
        sort(ans.begin(), ans.end());
        vector<vector<int>> res;
        //select first k or less than k(if no. of elements is less than k) element only
        for(int i=0; i<(int)min(k, (int)ans.size()); i++) {
            res.push_back({ans[i][2], ans[i][3]});
        }
        
        return res;
    }
};
