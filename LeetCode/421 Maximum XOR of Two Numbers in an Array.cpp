/** 
	Problem : Maximum XOR of Two Numbers in an Array
	topic : trie data structure
	time complexitiy: O(n * 32) , here 32 is no. of bits in number
	space complexity: In trie data structure we can not define the space complexity
					  but in wrost case we may assume: O(2 ^ 32)
	problem link: https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
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
            int bit = (num>>i) & 1;
            if(!node->containsKey(bit)) {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }
    int getMax(int num) {
        int maxNum = 0;
        Node* node = root;
        for(int i=31; i>=0; i--) {
            int bit = (num>>i) & 1;
            if(node->containsKey(1 - bit)) {
                maxNum = maxNum | (1<<i);
                node = node->get(1-bit);
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
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for(int i=0; i<nums.size(); i++) {
            trie.insert(nums[i]);
        }
        int ans = 0;
        for(int i=0; i<nums.size(); i++) {
            int maxNum = trie.getMax(nums[i]);
            ans = max(ans, maxNum);
        }
        return ans;
    }
};
