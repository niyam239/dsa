/** 
	Problem : Maximum XOR With an Element From Array
	topics : trie, offline queries 
	time complexitiy: O(n * 32) + O(n*log n) + O(q*log q),
					 here, 32 is no. of bits in number
					 	  n = no. of elements in nums array
					 	  q = no. of queries
	space complexity: In trie data structure we can not define the space complexity
					  but in wrost case we may assume: O(2 ^ 32) + O(3*q) //storing the queries
	problem link: https://leetcode.com/problems/maximum-xor-with-an-element-from-array/
**/

struct Node {
    Node* links[2];
    bool containsKey(int bit) {
        return (links[bit] != NULL);
    }
    Node* get(int bit) {
        return links[bit];
    }
    void put(int bit, Node* node) {
        links[bit] = node;
    }
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    void insert(int num) {
        Node* node = root;
        for(int i=31; i>=0; i--) {
            int bit = (num >> i) & 1;
            if(!node->containsKey(bit)) {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }
    int getMax(int num) {
        Node* node = root;
        int maxNum = 0;
        for(int i=31; i>=0; i--) {
            int bit = (num >> i) & 1;
            if(node->containsKey(1 - bit)) {
                maxNum = maxNum | (1 << i);
                node = node->get(1 - bit);
            }
            else {
                node = node->get(bit);
            }
        }
        return maxNum;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<vector<int>> arr;
        for(int i=0; i<queries.size(); i++) {
            arr.push_back({queries[i][1], queries[i][0], i});
        }
        sort(arr.begin(), arr.end());
        sort(nums.begin(), nums.end());
        vector<int> ans(queries.size(), -1);
        
        Trie trie;
        
        int ind = 0;
        for(int i=0; i<arr.size(); i++) {
            while(ind < nums.size() && nums[ind] <= arr[i][0]) {
                trie.insert(nums[ind]);
                ind++;
            }
            if(ind == 0) {
                ans[arr[i][2]] = -1;
            }
            else {
                ans[arr[i][2]] = trie.getMax(arr[i][1]);
            }
        }
        return ans;
    }
};
